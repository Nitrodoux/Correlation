#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
	double Y1[500], Y2[500];
	ifstream plik;
	plik.open("testujacy.txt"); // test set
	//plik.open("uczacy.txt"); // training set
	//plik.open("walidacyjny.txt"); //validation set
	double c, x1, x2, x3, y1, y2, y1sr, y2sr, y1suma=0, y2suma=0, licznik=0, mian1=0, mian2=0, korelacja, MSE=0; 
	int i = 0;
	while( true ) 
    {
        plik >> c >> x1 >> x2 >> x3 >> y1 >> y2;
        if( plik.good() ){
        Y1[i]=y1;
		Y2[i]=y2;
		i++;    
		}
        else
             break;
       
    }
    
    for (i=0;i<500;i++){
    	y1suma+=Y1[i];
    	y2suma+=Y2[i];
    	MSE+=(Y1[i]-Y2[i])*(Y1[i]-Y2[i]);
	}
	MSE/=500;
	y1sr=y1suma/500;
	y2sr=y2suma/500;
	
	for (i=0; i<500; i++){
		licznik+=(Y1[i]-y1sr)*(Y2[i]-y2sr);
		mian1+=(Y1[i]-y1sr)*(Y1[i]-y1sr);
		mian2+=(Y2[i]-y2sr)*(Y2[i]-y2sr);
	}
    
    korelacja = licznik/(sqrt(mian1)*sqrt(mian2));
    cout << "wspolczynnik korelacji R = " << korelacja << "\n"; //correlation ratio R
    cout << "MSE = " << MSE << "\n"; //MSE
    plik.close();
	return 0; 
}
