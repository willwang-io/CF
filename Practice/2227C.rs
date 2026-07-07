fn solve() {
    let n: usize = read();
    let mut a: Vec<Vec<i32>> = vec![vec![]; 4];
    for i in 0..n {
        let x: i32 = read();
        if x % 6 == 0 {
            a[0].push(x);
        } else if x % 2 == 0 {
            a[1].push(x);
        } else if x % 3 != 0 {
            a[2].push(x);
        } else {
            a[3].push(x);
        }
    }
    let mut first = true;
    for i in 0..4 {
        for &x in &a[i] {
            if !first {
                print!(" ");
            }
            first = false;
            print!("{x}");
        }
    }
    println!("");
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