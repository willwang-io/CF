// Created: Jul 26 2026, 13:15:10
use std::collections::VecDeque;

fn main() {
    let n: usize = read();
    let m: usize = read();
    let mut adj = vec![vec![]; n];

    for _ in 0..m {
        let a = read::<usize>() - 1;
        let b = read::<usize>() - 1;
        adj[a].push(b);
        adj[b].push(a);
    }

    let mut color = vec![0; n];

    for s in 0..n {
        if color[s] != 0 {
            continue;
        }

        color[s] = 1;
        let mut q = VecDeque::from([s]);

        while let Some(u) = q.pop_front() {
            for &v in &adj[u] {
                if color[v] == 0 {
                    color[v] = 3 - color[u];
                    q.push_back(v);
                } else if color[v] == color[u] {
                    println!("IMPOSSIBLE");
                    return;
                }
            }
        }
    }
    let ans = color
        .iter()
        .map(|x| x.to_string())
        .collect::<Vec<_>>()
        .join(" ");
    println!("{ans}");
}

thread_local! {
    pub static INPUT: std::cell::RefCell<std::str::SplitAsciiWhitespace<'static>> = std::cell::RefCell::<std::str::SplitAsciiWhitespace<'static>>::new({
        let mut input = String::new();
        std::io::Read::read_to_string(&mut std::io::stdin(), &mut input).unwrap();
        Box::leak(input.into_boxed_str()).split_ascii_whitespace()
    });
}

pub fn read<T: std::str::FromStr>() -> T
where
    T::Err: std::fmt::Debug,
{
    INPUT.with(|input| input.borrow_mut().next().unwrap().parse().unwrap())
}
