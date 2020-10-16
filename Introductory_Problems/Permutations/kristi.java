import java.io.*;
import java.util.*;
public class Permutations{
    public static void main(String args[])throws IOException
    {
    InputStreamReader r=new InputStreamReader(System.in);    
    Scanner sc=new Scanner(System.in);
    BufferedReader br=new BufferedReader(r);
    long n=Long.parseLong(br.readLine());
    if(n==1)
        System.out.println(n);
    else if(n<4)
        System.out.println("NO SOLUTION");
    
    else
    {
        for(int i=2; i<=n; i+=2)
            System.out.println(i+" ");
        for(int i=1; i<=n; i+=2)
            System.out.println(i+" ");

    }
    
}
}