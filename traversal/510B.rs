// Created: Jul 26 2026, 20:46:28
// Formatted with rustfmt.

fn main() {
    let n: usize = read();
    let m: usize = read();
    let a: Vec<Vec<u8>> = (0..n).map(|_| read::<String>().into_bytes()).collect();
    let d = [(0, 1), (1, 0), (-1, 0), (0, -1)];
    let mut vis = vec![vec![false; m]; n];
    let mut par = vec![vec![None; m]; n];

    for i in 0..n {
        for j in 0..m {
            if vis[i][j] {
                continue;
            }

            let mut stack = vec![(i, j)];
            vis[i][j] = true;

            while let Some((x, y)) = stack.pop() {
                for &(dx, dy) in &d {
                    let nx = x as i32 + dx;
                    let ny = y as i32 + dy;

                    if nx < 0 || ny < 0 || nx >= n as i32 || ny >= m as i32 {
                        continue;
                    }

                    let nx = nx as usize;
                    let ny = ny as usize;

                    if a[nx][ny] != a[i][j] {
                        continue;
                    }

                    if vis[nx][ny] {
                        if par[x][y] != Some((nx, ny)) {
                            println!("Yes");
                            return;
                        }
                        continue;
                    }

                    vis[nx][ny] = true;
                    par[nx][ny] = Some((x, y));
                    stack.push((nx, ny));
                }
            }
        }
    }

    println!("No");
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
