package os_lab_2_netbeans;
 
import java.util.Scanner;
import javax.swing.JFrame;
 
public class Os_lab_2_netbeans {
 
 
    public static void main(String[] args) {
        Scanner scr = new Scanner(System.in);
		int lms,pms,pu,lma,pma,ptn,i,j,pn,offset,fn,l1,l2,n,n1;
		int[] pt =new int[10];
 
		System.out.println("Enter Logical memory size :");
		lms=scr.nextInt();
		System.out.println("Enter Physical memory size :");
		pms=scr.nextInt();
		System.out.println("Enter paging unit size :");
		pu=scr.nextInt();
		System.out.println("Enter number of element in page table :");
		ptn=scr.nextInt();
		for(i=0;i<ptn;i++) {
			System.out.println("Enter Page "+i+" Frame number  :");
			pt[i]=scr.nextInt();
		}
		System.out.println("Enter logical memory address :");
		lma=scr.nextInt();
		pn=lma/pu;
	        offset=lma-(pn*pu);
	        fn=pt[pn];
	        pma=pu*fn+offset;
	        n=lms/pu;
                n1=pms/pu;
	        System.out.println(pma);
	        page_print pg =new page_print(n,pu,n1,ptn,pt);
                JFrame f = pg.getframe(); 
                f.add(pg);
    }
 
}
