// Created: Jul 27 2026, 00:35:04
// Formatted with rustfmt.

fn main() {
    let n: usize = read();
    let k: usize = read();

    let mut adj = vec![vec![]; n];
    for _ in 0..n - 1 {
        let u = read::<usize>() - 1;
        let v = read::<usize>() - 1;
        adj[u].push(v);
        adj[v].push(u);
    }

    let mut parent = vec![None; n];
    let mut depth = vec![0i64; n];
    let mut order = Vec::with_capacity(n);
    let mut stack = vec![0];

    while let Some(u) = stack.pop() {
        order.push(u);

        for &v in &adj[u] {
            if parent[u] == Some(v) {
                continue;
            }

            parent[v] = Some(u);
            depth[v] = depth[u] + 1;
            stack.push(v);
        }
    }

    let mut subtree_size = vec![1i64; n];
    for &u in order.iter().rev() {
        if let Some(p) = parent[u] {
            subtree_size[p] += subtree_size[u];
        }
    }

    let mut priority: Vec<i64> = (0..n).map(|u| depth[u] - subtree_size[u] + 1).collect();
    priority.sort_unstable();
    let ans: i64 = priority[n - k..].iter().sum();
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
