fn solve() {
    let n: usize = read();
    let s: String = read();
    let x = n.isqrt();
    if x * x != n {
        println!("No");
        return;
    }
    let tmp: Vec<&[u8]> = s.as_bytes().chunks_exact(x).collect();
    for i in 0..x {
        if i == 0 || i == x - 1 {
            if tmp[i].iter().any(|&x| x != b'1') {
                println!("No");
                return;
            }
        } else {
            if tmp[i][0] != b'1'
                || tmp[i][x - 1] != b'1'
                || tmp[i][1..x - 1].iter().any(|&x| x == b'1')
            {
                println!("No");
                return;
            }
        }
    }
    println!("Yes");
}

fn main() {
    let t: usize = read();
    for _ in 0..t {
        solve();
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
