fn solve() {
    let s: String = read();
    let mut keys = [false; 3];
    for c in s.chars() {
        if c == 'r' {
            keys[0] = true;
        } else if c == 'g' {
            keys[1] = true;
        } else if c == 'b' {
            keys[2] = true;
        } else if (c == 'R' && !keys[0]) || (c == 'G' && !keys[1]) || (c == 'B' && !keys[2]) {
            println!("NO");
            return;
        }
    }
    println!("YES");
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
