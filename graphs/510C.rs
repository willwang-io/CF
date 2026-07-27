// Created: Jul 27 2026, 00:55:41
// Formatted with rustfmt.
use std::collections::VecDeque;

fn topological_sort(adj: &[Vec<usize>]) -> Option<Vec<usize>> {
    let n = adj.len();
    let mut indegree = vec![0; n];

    for edges in adj {
        for &v in edges {
            indegree[v] += 1;
        }
    }

    let mut q = VecDeque::new();

    for i in 0..n {
        if indegree[i] == 0 {
            q.push_back(i);
        }
    }

    let mut order = Vec::with_capacity(n);

    while let Some(u) = q.pop_front() {
        order.push(u);

        for &v in &adj[u] {
            indegree[v] -= 1;

            if indegree[v] == 0 {
                q.push_back(v);
            }
        }
    }

    if order.len() == n {
        Some(order)
    } else {
        None
    }
}

fn main() {
    let n: usize = read();
    let a: Vec<String> = (0..n).map(|_| read()).collect();

    let mut adj = vec![vec![]; 26];
    for i in 1..n {
        match a[i].bytes().zip(a[i - 1].bytes()).find(|(x, y)| x != y) {
            Some((x, y)) => {
                adj[(x - b'a') as usize].push((y - b'a') as usize);
            }
            None => {
                if a[i - 1].len() > a[i].len() {
                    println!("Impossible");
                    return;
                }
            }
        }
    }

    match topological_sort(&adj) {
        Some(order) => {
            let ans = order
                .into_iter()
                .rev()
                .map(|c| (c as u8 + b'a') as char)
                .collect::<String>();
            println!("{ans}");
        }
        None => {
            println!("Impossible");
        }
    }
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
