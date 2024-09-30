package google2;

public class Answer {

	public static int answer(int src, int dest) { 
		int deltaX;
		int deltaY;
		int m; 
		int mPrime;
		int x1,y1,x2,y2;
		
        // coordinates
		x1= src/8;
		y1= src%8;
		x2= dest/8;
		y2= dest%8;
		deltaX = Math.abs(x2-x1);
		deltaY = Math.abs(y2-y1);
		
		int XPlusYoverThree = ((deltaX + deltaY) %3 > 0)?(deltaX + deltaY) /3 +1:(deltaX + deltaY) /3 ;
		int Xover2 = ((deltaX % 2) >0)? (deltaX / 2) +1 :(deltaX / 2);
		int Yover2 = ((deltaY % 2)>0)? (deltaY / 2)+1:(deltaY / 2);
		
		mPrime = Math.max( ((deltaX + deltaY) %3 > 0)?(deltaX + deltaY) /3 +1:(deltaX + deltaY) /3 , Math.max( ((deltaX % 2) >0)? (deltaX / 2) +1 :(deltaX / 2),((deltaY % 2)>0)? (deltaY / 2)+1:(deltaY / 2)));
		System.out.println("x+y/3 " + XPlusYoverThree);
		System.out.println("Xover2 " +Xover2);
		System.out.println("Yover2 " +Yover2);
		if(deltaX ==2 && deltaY ==2){
			m=4;
		}else if(deltaX + deltaY == 1){
			m=3;
		}else if (deltaX ==1 && deltaY==1 && (src == 0 || src ==7 || src == 56 || src == 63)){
			m=4;
		}else
		m = mPrime + (mPrime + deltaX + deltaY) % 2;
		
		System.out.println("m= " +m + " mPrime= " +mPrime +" deltaX= " +deltaX +" deltaY= " +deltaY );
		return m;
    } 
	
	
	public static void main(String[] args) {
		
		Answer.answer(20, 16);
		
		
	}

}
