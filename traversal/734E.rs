// Created: Aug  1 2026, 13:40:49
// Formatted with rustfmt.

fn farthest(start: usize, adj: &[Vec<usize>]) -> (usize, usize) {
    let mut stack = vec![(start, None, 0)];
    let mut ans = (start, 0);

    while let Some((u, par, dist)) = stack.pop() {
        if dist > ans.1 {
            ans = (u, dist);
        }
        for &v in &adj[u] {
            if Some(v) != par {
                stack.push((v, Some(u), dist + 1));
            }
        }
    }

    ans
}

fn solve() {
    let n: usize = read();
    let colours: Vec<i32> = (0..n).map(|_| read()).collect();
    let mut edges = vec![];
    let mut adj = vec![vec![]; n];

    for _ in 0..n - 1 {
        let u = read::<usize>() - 1;
        let v = read::<usize>() - 1;

        adj[u].push(v);
        adj[v].push(u);
        edges.push((u, v));
    }

    let mut comp = vec![None; n];
    let mut comp_idx = 0;

    for i in 0..n {
        if comp[i].is_some() {
            continue;
        }

        let mut stack = vec![i];
        comp[i] = Some(comp_idx);

        while let Some(u) = stack.pop() {
            for &v in &adj[u] {
                if comp[v].is_some() || colours[v] != colours[u] {
                    continue;
                }
                comp[v] = Some(comp_idx);
                stack.push(v);
            }
        }

        comp_idx += 1;
    }

    let mut comp_tree = vec![vec![]; comp_idx];
    for &(u, v) in &edges {
        let a = comp[u].unwrap();
        let b = comp[v].unwrap();
        if a != b {
            comp_tree[a].push(b);
            comp_tree[b].push(a);
        }
    }

    let (a, _) = farthest(0, &comp_tree);
    let (b, diameter) = farthest(a, &comp_tree);

    println!("{}", (diameter + 1) / 2);
}

fn main() {
    solve();
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
