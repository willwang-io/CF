fn main() {
    let n: usize = read();
    let m: usize = read();
    let mut grid: Vec<Vec<char>> = (0..n)
        .map(|_| read::<String>().chars().collect())
        .collect();
    let mut ans = 0;
    for i in 0..n {
        if grid[i].iter().any(|&c| c == 'S') {
            continue;
        }
        for j in 0..m {
            grid[i][j] = '#';
        }
    }
    for j in 0..m {
        let mut ok = true;
        for i in 0..n {
            if grid[i][j] == 'S' {
                ok = false;
            }
        }
        if ok {
            for i in 0..n {
                grid[i][j] = '#';
            }
        }
    }
    let ans: usize = grid.iter().map(|row| row.iter().filter(|&&c| c == '#').count()).sum();
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