fn solve() {
    let n: usize = read();
    let mut mx1 = i32::MIN;
    let mut mx2 = i32::MIN;
    let mut a: Vec<i32> = vec![0; n];
    for i in 0..n {
        a[i] = read();
        if mx1 == i32::MIN {
            mx1 = a[i];
        } else {
            if a[i] > mx1 {
                mx2 = mx1;
                mx1 = a[i];
            } else if a[i] > mx2 {
                mx2 = a[i];
            }
        }
    }
    for x in a {
        if x == mx1 {
            print!("{} ", x - mx2);
        } else {
            print!("{} ", x - mx1);
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