// https://cses.fi/problemset/task/1094
use std::io::stdin;
fn main(){
    let mut inp: String = String::new();
    stdin().read_line(&mut inp).expect("Error in input");
    let n: u64 = inp.trim().parse().expect("Error in parsing to int");
    inp.clear();
    stdin().read_line(&mut inp).expect("Error in input");
    let n: Vec<u64> = inp.split_whitespace().map(|s| s.parse().expect("Error in input")).collect();
    let mut res: u64 = 0;
    let mut temp = n[0];
    for i in n{
        if temp<=i{
            temp=i;
        }else{
            res=res+temp-i;
        }
    }
    println!("{}",res);
}