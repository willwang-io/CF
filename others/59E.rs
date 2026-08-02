use std::cmp::Reverse;
use std::collections::BinaryHeap;

const INF: i64 = i64::MAX / 4;

fn dijkstra(
    s: usize,
    dist: &mut [i64],
    parent: &mut [Option<usize>],
    adj: &[Vec<(usize, i64)>],
    ok: &[Vec<Vec<bool>>],
) {
    dist.fill(INF);
    parent.fill(None);

    let mut heap = BinaryHeap::new();

    dist[s] = 0;
    heap.push(Reverse((0_i64, s, 0)));

    while let Some(Reverse((current_dist, cur, prev))) = heap.pop() {
        if current_dist != dist[cur] {
            continue;
        }

        for &(to, weight) in &adj[cur] {
            if !ok[prev][cur][to] {
                continue;
            }

            let new_dist = current_dist + weight;

            if new_dist < dist[to] {
                dist[to] = new_dist;
                parent[to] = Some(cur);
                heap.push(Reverse((new_dist, to, cur)));
            }
        }
    }
}

fn restore_path(s: usize, t: usize, parent: &[Option<usize>]) -> Option<Vec<usize>> {
    let mut path = vec![];
    let mut v = t;

    while v != s {
        path.push(v);
        v = parent[v]?;
    }

    path.push(s);
    path.reverse();

    Some(path)
}

fn main() {
    let n: usize = read();
    let m: usize = read();
    let k: usize = read();
    let mut adj: Vec<Vec<(usize, i64)>> = vec![vec![]; n + 1];

    for _ in 0..m {
        let a: usize = read::<usize>();
        let b: usize = read::<usize>();
        adj[a].push((b, 1));
        adj[b].push((a, 1));
    }

    let mut ok: Vec<Vec<Vec<bool>>> = vec![vec![vec![true; n + 1]; n + 1]; n + 1];

    for _ in 0..k {
        let a: usize = read::<usize>();
        let b: usize = read::<usize>();
        let c: usize = read::<usize>();
        ok[a][b][c] = false;
    }

    let mut dist = vec![INF; n + 1];
    let mut parent = vec![None; n + 1];

    dijkstra(0, &mut dist, &mut parent, &adj, &ok);

    match restore_path(0, n - 1, &parent) {
        Some(path) => {
            let out = path
                .iter()
                .map(|&v| (v + 1).to_string())
                .collect::<Vec<_>>()
                .join(" ");
            println!("{out}");
        }
        None => println!("-1"),
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
