// Created: Jul 26 2026, 12:56:00

fn connected_components(adj: &[Vec<usize>]) -> Vec<Vec<usize>> {
    let n = adj.len();
    let mut vis = vec![false; n];
    let mut comps = Vec::new();

    for s in 0..n {
        if vis[s] {
            continue;
        }

        let mut comp = Vec::new();
        let mut stack = vec![s];
        vis[s] = true;

        while let Some(u) = stack.pop() {
            comp.push(u);

            for &v in &adj[u] {
                if !vis[v] {
                    vis[v] = true;
                    stack.push(v);
                }
            }
        }

        comps.push(comp);
    }

    comps
}

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

    let comps = connected_components(&adj);

    println!("{}", comps.len() - 1);
    let s = comps[0][0];

    for i in 1..comps.len() {
        println!("{} {}", s + 1, comps[i][0] + 1);
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
