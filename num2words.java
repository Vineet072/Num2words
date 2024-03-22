import java.util.Scanner;
import java.util.ArrayList;
import java.lang.Math;

public class Main {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);

        System.out.print("Enter your number to be modified:");
        int e=scanner.nextInt();
        scanner.close();
        String[] a={"ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN","ELEVEN","TWELVE","THIRTEEN","FOURTEEN","FIFTEEN","SIXTEEN","SEVENTEEN","EIGHTEEN","NINETEEN"};
        String[] b={"TWENTY","THIRTY","FORTY","FIFTY","SIXTY","SEVENTY","EIGHTY","NINETY"};
        String[] c={"HUNDRED","THOUSAND","LAKH","CRORE"};
        ArrayList<String> d=new ArrayList<>();

        //=0
        if(e==0) {
            System.out.print("ZERO");
        }
        
        //<0
        if(e<0) {
            e=-e;
        }

    //Crore
    int f=Math.floorDiv(e%(1000000000), 10000000);
    if (f<20 && f>0) {
        d.add(a[f-1]);
        d.add(c[3]);
    }
    else if (f>19) {
        if (f%10==0) {
            d.add(b[Math.floorDiv(f, 10)-2]);
            d.add(c[3]);
        }
        else if (f%10>0) {
            d.add(b[Math.floorDiv(f, 10)-2]);
            d.add(a[-1+f%10]);
            d.add(c[3]);
        }
    }

    //Lakh
    f=Math.floorDiv(e%10000000, 100000);
    if (f<20 && f>0) {
        d.add(a[f-1]);
        d.add(c[2]);
    }
    else if (f>19) {
        if (f%10==0) {
            d.add(b[Math.floorDiv(f, 10)-2]);
            d.add(c[2]);
        }
        else if (f%10>0) {
            d.add(b[Math.floorDiv(f, 10)-2]);
            d.add(a[-1+f%10]);
            d.add(c[2]);
        }
    }

    //Thousand
    f=Math.floorDiv(e%100000, 1000);
    if (f<20 && f>0) {
        d.add(a[f-1]);
        d.add(c[1]);
    }
    else if (f>19) {
        if (f%10==0) {
            d.add(b[Math.floorDiv(f, 10)-2]);
            d.add(c[1]);
        }
        else if (f%10>0) {
            d.add(b[Math.floorDiv(f, 10)-2]);
            d.add(a[-1+f%10]);
            d.add(c[1]);
        }
    }

    //Hundred
    if (Math.floorDiv(e%1000, 100)>0) {
        d.add(a[-1+Math.floorDiv(e%1000, 100)]);
        d.add(c[0]);
    }

    //<100
    f=e%100;
    if (f<20 && f>0) {
        d.add(a[f-1]);
    }
    else if (f>19) {
        if (f%10==0) {
            d.add(b[Math.floorDiv(f, 10)-2]);
        }
        else if (f%10>0) {
            d.add(b[Math.floorDiv(f, 10)-2]);
            d.add(a[-1+f%10]);
        }
    }

    for(String element : d) {
        System.out.print(element+" ");
    }
    System.out.println();
    }
}