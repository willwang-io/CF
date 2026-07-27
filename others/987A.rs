fn solve() {
    let mut tmp =
        std::collections::HashSet::from(["Power", "Time", "Space", "Soul", "Reality", "Mind"]);
    let n: usize = read();
    for _ in 0..n {
        let s: String = read();
        if s == "purple" {
            tmp.remove("Power");
        } else if s == "green" {
            tmp.remove("Time");
        } else if s == "blue" {
            tmp.remove("Space");
        } else if s == "orange" {
            tmp.remove("Soul");
        } else if s == "red" {
            tmp.remove("Reality");
        } else {
            tmp.remove("Mind");
        }
    }
    println!("{}", tmp.len());
    for x in tmp {
        println!("{x}");
    }
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
