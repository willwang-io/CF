// Created: Jul 26 2026, 19:22:40
// Formatted with rustfmt.
use std::collections::VecDeque;

fn main() {
    let n: usize = read();
    let m: usize = read();
    let k: usize = read();
    let a: Vec<Vec<u8>> = (0..n).map(|_| read::<String>().into_bytes()).collect();

    let s: usize = a
        .iter()
        .map(|row| row.iter().filter(|&&b| b == b'.').count())
        .sum();

    let mut cnt = s - k;
    let mut vis = vec![vec![false; m]; n];
    let d = [(1, 0), (-1, 0), (0, 1), (0, -1)];

    for i in 0..n {
        for j in 0..m {
            if a[i][j] == b'.' && cnt > 0 {
                let mut q = VecDeque::new();
                q.push_back((i, j));
                vis[i][j] = true;
                cnt -= 1;

                while let Some((x, y)) = q.pop_front() {
                    for &(dx, dy) in &d {
                        let nx = x as i32 + dx;
                        let ny = y as i32 + dy;

                        if nx < 0 || nx >= n as i32 || ny < 0 || ny >= m as i32 {
                            continue;
                        }

                        let nx = nx as usize;
                        let ny = ny as usize;

                        if a[nx][ny] == b'#' || vis[nx][ny] || cnt == 0 {
                            continue;
                        }

                        vis[nx][ny] = true;
                        cnt -= 1;
                        q.push_back((nx, ny));
                    }
                }
            }
        }
    }

    let ans = (0..n)
        .map(|i| {
            (0..m)
                .map(|j| {
                    if !vis[i][j] && a[i][j] == b'.' {
                        'X'
                    } else {
                        a[i][j] as char
                    }
                })
                .collect::<String>()
        })
        .collect::<Vec<_>>()
        .join("\n");

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
