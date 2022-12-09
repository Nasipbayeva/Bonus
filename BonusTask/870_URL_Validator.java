import java.net.URL;
import java.util.Scanner;
  
class Test {
  
    public static boolean isValid(String url)
    {
       try {
            new URL(url).toURI();
            return true;
        }
       catch (Exception e) {
            return false;
        }
    }
      
   
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        String url1 = scan.next();
        if (isValid(url1)) 
            System.out.println("YES");
        else
            System.out.println("NO");     
             
    }
}