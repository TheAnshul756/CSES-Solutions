//https://cses.fi/problemset/task/1083
use std::io::stdin;

fn main() {
    let mut inp = String::new();
    stdin()
        .read_line(&mut inp)
        .expect("Error in reading input");
    let n:u64 = inp.trim().parse().expect("Input not number");
    let mut arr = [0; 2usize * 10usize.pow(5) + 10usize];
    inp.clear();
        std::io::stdin()
        .read_line(&mut inp)
        .expect("Error in reading input");
    let elements:Vec<i32> = inp.split_whitespace().map(|s| s.parse().expect("Not a number")).collect();
    for i in elements{
        arr[i as usize] = 1;
    }
    for i in 1..=n {
        if arr[i as usize]==0{
            print!("{}", i);
            return
        }
    }

}
