use std::{
    io::{self, Read},
    str::SplitWhitespace,
};

fn solve(io: &mut FastIO) -> () {
    let n: i32 = io.read();
    let k: i32 = io.read();
    let x: i32 = io.read();
    if x != 1 {
        println!("YES");
        println!("{}", n);
        for _ in 0..n {
            print!("{} ", 1);
        }
        println!();
    } else {
        if k == 1 || (k == 2 && n % 2 == 1) {
            println!("NO");
        } else {
            println!("YES");
            if n % 2 == 0 {
                println!("{}", n / 2);
                for _ in 0..n / 2 {
                    print!("{} ", 2);
                }
                println!();
            } else {
                println!("{}\n3 ", (n - 3) / 2 + 1);
                for _ in 0..(n - 3) / 2 {
                    print!("{} ", 2);
                }
                println!();
            }
        }
    }
}

fn main() {
    let mut io = FastIO::new();
    let t: usize = io.read();
    for _ in 0..t {
        solve(&mut io);
    }
}

struct FastIO {
    iter: SplitWhitespace<'static>,
}

impl FastIO {
    fn new() -> Self {
        let mut buf = String::new();
        io::stdin().read_to_string(&mut buf).unwrap();
        let s: &'static str = Box::leak(buf.into_boxed_str());

        FastIO {
            iter: s.split_whitespace(),
        }
    }

    fn read<T: std::str::FromStr>(&mut self) -> T
    where
        T::Err: std::fmt::Debug,
    {
        self.iter.next().unwrap().parse().unwrap()
    }
}