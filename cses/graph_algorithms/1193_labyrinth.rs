// Created: Jul 26 2026, 12:02:44
use std::collections::VecDeque;

fn main() {
    let n: usize = read();
    let m: usize = read();
    let g: Vec<Vec<u8>> = (0..n).map(|_| read::<String>().bytes().collect()).collect();

    let mut vis = vec![vec![false; m]; n];
    let mut par = vec![vec![None; m]; n];
    let mut q = VecDeque::new();
    let d = [(1, 0), (-1, 0), (0, 1), (0, -1)];

    let mut sr = 0;
    let mut sc = 0;
    let mut tr = 0;
    let mut tc = 0;

    for i in 0..n {
        for j in 0..m {
            if g[i][j] == b'A' {
                q.push_back((i, j));
                vis[i][j] = true;
                sr = i;
                sc = j;
            } else if g[i][j] == b'B' {
                tr = i;
                tc = j;
            }
        }
    }

    while let Some((r, c)) = q.pop_front() {
        if r == tr && c == tc {
            break;
        }

        for &(dr, dc) in &d {
            let nr = r as i32 + dr;
            let nc = c as i32 + dc;

            if nr < 0 || nr >= n as i32 || nc < 0 || nc >= m as i32 {
                continue;
            }

            let nr = nr as usize;
            let nc = nc as usize;

            if g[nr][nc] == b'#' || vis[nr][nc] {
                continue;
            }

            vis[nr][nc] = true;
            par[nr][nc] = Some((r, c));
            q.push_back((nr, nc));
        }
    }

    if !vis[tr][tc] {
        println!("NO");
        return;
    }

    println!("YES");
    let mut path = vec![];

    let mut cur_r = tr;
    let mut cur_c = tc;

    while (cur_r, cur_c) != (sr, sc) {
        let (pr, pc) = par[cur_r][cur_c].unwrap();

        if pr == cur_r + 1 {
            path.push(b'U');
        } else if pr + 1 == cur_r {
            path.push(b'D');
        } else if pc == cur_c + 1 {
            path.push(b'L');
        } else {
            path.push(b'R');
        }

        (cur_r, cur_c) = (pr, pc);
    }

    println!("{}", path.len());
    path.reverse();
    println!("{}", String::from_utf8(path).unwrap());
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
