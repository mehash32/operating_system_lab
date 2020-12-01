package os_lab_2_netbeans;
 
import javax.swing.*;
import java.awt.*;
 
public class page_print extends JPanel  {
	int n,pu,l1=100,l2=100,i,t=0,t1,n1,ptn;
        int [] pt =new int [10];
	JFrame j = new JFrame();
	public page_print(int n,int pu,int n1,int ptn,int[] pt)
	{
		this.n=n;
                                             this.n1=n1;
		this.pu=pu;
                                             this.ptn=ptn;
                                             this.pt=pt;
 
		j.setTitle("Paging ");
		j.setSize(1000,700);
                                             j.setResizable(false);
		j.setVisible(true);
		j.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
 
        JFrame getframe()
        {
            return j;
        }
	public void paint(Graphics g)
	{
 
 
		for(i=0;i<=n;i++) {
			g.drawRect(100, l1, 70, 40);
                        g.drawString("Page "+i, 100+15, l1+20);
                        t1=t+pu-1;
                        g.drawString(t+" - "+t1, 100-50, l1+22);
                        t=t1+1;
			l1=l1+40;
 
		}
                t=0;
                for(i=0;i<=n1;i++){
                    g.drawRect(300, l2, 70, 40);
                        g.drawString("Frame "+i, 300+15, l2+20);
                        t1=t+pu-1;
                        g.drawString(t+" - "+t1, 300-50, l2+22);
                        t=t1+1;
			l2=l2+40;
                }
                l2=100;
                for(i=0;i<ptn;i++){
                    g.drawRect(500, l2, 70, 40);
                    g.drawString("Page "+i, 500-50, l2+22);
                    g.drawString("Frame "+pt[i], 500+15, l2+20);
                    l2=l2+40;
                }
 
 
	}
 
}