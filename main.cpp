#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <ctime>    // For time()
#include <cstdlib>
using namespace std;
int minimum(int a, int b,int c)
{int d,min;
    if(a<b)
       d=a;
    else d=b;
    if(d<c)min=d;
        else min=c;
        return min;
}
string conct(string a,int b,string c){
return a + std::to_string(b) +c;
}
int main()
{
    int k,l;
    srand(time(0));
    ofstream fout;
    ifstream fin;
    string a;
    char b;
    fout.open("output.txt");
    double wil[25][500]={0};
for(int t=0;t<500;t++){
    cout<<t<<endl;
    int i=0,j=0;
    vector<vector<int>> A;
    vector<int> row;
    vector<int> e;
	string c=conct("matrix",t,".txt");
    fin.open(c, ios::in); // by default mode
    cout<<c;
    while(!fin.eof()){
        //getline(cin,a);
        fin.get(b);
       // cout<<b<<endl;
        if(b=='1'){row.push_back(1);j++;}
        else if(b=='0'){row.push_back(0);j++;}
        else if(b=='+'||b=='-'){
                A.push_back(row);
                row.clear();
            if(b=='+')e.push_back(1);
            if(b=='-')e.push_back(0);
            i++;
            j=0;
        }else continue;
    }


    //cout<<i<<A[0].size();
    int C = A[0].size();
    //cout<<"for3"<<endl;
    int T = i;
    int n=A.size(),m=A[0].size();
    int o=0;
    double rnk[25][m];
    double p[n];
    //main for loop
    for(o=0;o<m;o++){
        n=e.size();
        for(int k=0;k<n;k++){
            if(A[k][o]==1){
            	// p[k] = 0.2;
			e[k]=1;}
            else {
			e[k]=0;
			//p[k]=1;
		}
            }
        double E[m],N[m],Ef[m],Ep[m],Nf[m],Np[m];
        for( k=0;k<m;k++){
            E[k]=0,N[k]=0,Ef[k]=0,Ep[k]=0,Nf[k]=0,Np[k]=0;
            for( l=0;l<n;l++){
                   if(A[l][k]==1 && e[l]==1) Ep[k]++;
                   if(A[l][k]==1 && e[l]==0) Ef[k]++;
                   if(A[l][k]==0 && e[l]==1) Np[k]++;
                   if(A[l][k]==0 && e[l]==0) Nf[k]++;
                }
               // double j=Ef[k];
               // Ef[k] = Ef[k];
                //Ep[k] = Ep[k];
                 N[k]=Nf[k]+Np[k];
                 E[k]=Ef[k]+Ep[k];
            }
        i=0;
        double S[25][m],h;
        for(i=0;i<25;i++)
        {
          for(k=0;k<m;k++)
         {
            if(i==0)
            {
                if((Ef[k]+Nf[k])==0 || (Ep[k]+Np[k]) ==0 || Ef[k] ==0 || Ep[k] ==0 )
              {
                  S[i][k]=0;
              }
                else S[i][k]=(Ef[k]/(Ef[k]+Nf[k]))/((Ef[k]/(Ef[k]+Nf[k]))+(Ep[k]/(Ep[k]+Np[k])));
          }
            else if(i==1)
            {
                if(Ef[k]==0 || (Ef[k]+Nf[k])==0 || (Ep[k]+Np[k]) == 0)
                {
                  S[i][k]=0;
                }
                else
                S[i][k]=Ef[k]/sqrt((Ef[k]+Nf[k])*(Ep[k]+Np[k]));
            }
            else if (i==2)
            {
                if((Ef[k]+Ep[k]+Nf[k])==0 || Ef[k]==0) S[i][k]=0;
                else   S[i][k]= Ef[k]/(Ef[k]+Ep[k]+Nf[k]);
            }
            else if(i==3)
            {
                if(Ef[k]+Ep[k]+Nf[k]+Np[k] == 0) S[i][k]=0;
                else S[i][k]= (Ef[k]+Np[k])/(Ef[k]+Ep[k]+Nf[k]+Np[k]);
            }
            else if(i==4)
            {
                if((2*Ef[k] + Ep[k] + Nf[k])==0) S[i][k]=0;
                else S[i][k]=(2*Ef[k])/(2*Ef[k] + Ep[k] + Nf[k]);
            }
            else if(i==5)
            {
                if((Ep[k]+Nf[k])==0) S[i][k]=0;
                else S[i][k]=Ef[k]/(Ep[k]+Nf[k]);
            }
            else if (i==6)
            {
                if((Ef[k]+Ep[k]+Nf[k]+Np[k])==0) S[i][k]=0;
                else S[i][k]= Ef[k]/(Ef[k]+Ep[k]+Nf[k]+Np[k]);
            }
            else if(i==7)
            {
                if(Ef[k]+Ep[k]+(2*Nf[k])+Np[k] == 0) S[i][k]=0;
                else S[i][k]= (Ef[k]+Np[k])/(Ef[k]+Ep[k]+(2*Nf[k])+Np[k]);
            }
            else if(i==8)
            {
                if((Ep[k]+Nf[k])==0) S[i][k]=0;
                else S[i][k]= (Ef[k]+Np[k])/(Ep[k]+Nf[k]);
            }
            else if(i==9)
            {
                if((Ef[k]+Np[k]+(2*Ep[k])+2*Nf[k])==0)S[i][k]=0;
                else S[i][k]= Ef[k]/(Ef[k]+Np[k]+(2*Ep[k])+2*Nf[k]);
             }
            else if(i==10)
            {
                if(minimum(Ef[k],Ep[k],Nf[k])==0)S[i][k]=0;
                else S[i][k]= Ef[k]/minimum(Ef[k],Ep[k],Nf[k]);
            }
            else if(i==11)
            {
                if(sqrt((Ef[k]+Ep[k])*(Nf[k]+Np[k])*(Ef[k]+Np[k])*(Nf[k]+Ep[k]))==0) S[i][k]=0;
                else S[i][k]= (Ef[k]*Np[k])/sqrt((Ef[k]+Ep[k])*(Nf[k]+Np[k])*(Ef[k]+Np[k])*(Nf[k]+Ep[k]));
            }
            else if(i==12)
            {
                if((E[k]+Nf[k])==0)S[i][k]=0;
                else S[i][k]= 2*Ef[k]/(E[k]+Nf[k]);
            }
            else if(i==13)
            {
                if((Ef[k]+Nf[k]==0) || (Ep[k]+Np[k])==0) S[i][k]=0;
                else     S[i][k]=abs(Ef[k]/(Ef[k]+Nf[k])-(Ep[k]/(Ep[k]+Np[k])));
            }
            else if(i==14)
            {
                if((E[k]+N[k])==0) S[i][k]=0;

                else S[i][k]= (Ef[k]-Ep[k]+Np[k]-Nf[k])/(E[k]+N[k]);
            }
            else if(i==15)
            {
                if((Ef[k]+Ep[k]+Nf[k]+((10000*Nf[k]*Ep[k])/Ef[k]))==0 || Ef[k]==0) S[i][k]=0;
                else S[i][k]=Ef[k]/(Ef[k]+Ep[k]+Nf[k]+((10000*Nf[k]*Ep[k])/Ef[k]));
            }
            else if(i==16)
            {
                if((2*Ef[k]+Nf[k]+Ep[k])==0) S[i][k]=0;
                else S[i][k]= (2*Ef[k] - Nf[k]-Ep[k])/(2*Ef[k]+Nf[k]+Ep[k]);
            }
            else if(i==17)
            {
                if((2*E[k]+N[k])==0) S[i][k]=0;
                else S[i][k]= (2*(Ef[k]+Ep[k]))/(2*E[k]+N[k]);//doubt sokal
            }
            else if(i==18) S[i][k]=Ef[k]+Np[k];
            else if(i==19)
            {
                if((Ef[k]+Nf[k])==0 || (Np[k]+Nf[k])==0) S[i][k]=0;
                else S[i][k]= (Ef[k]/(Ef[k]+Nf[k]) + (Ef[k]/(Np[k]+Nf[k])))/2;
            }
            else if(i==20) S[i][k]=sqrt(Ef[k]+Np[k]);
            else if(i==21)
            {if ((Ef[k]+2*Ep[k] + 2*Nf[k])==0)S[i][k]=0;
            else S[i][k]= Ef[k]/(Ef[k]+2*Ep[k] + 2*Nf[k]);}
            else if(i==22) S[i][k]= Ef[k];
            else if(i==23) S[i][k]= (Ef[k] - Ep[k]);
            else if(i==24)
            {
              if(Ep[k]<=2) h=Ep[k];
              else if(2<=Ep[k] && Ep[k]<=10) h= 2+(0.1*(Ep[k]-2));
              else h=2.8+(0.01*(Ep[k]-10));
              S[i][k]=Ef[k]-h;
            }
         }
        }
        //n=i;

         for( l=0;l<25;l++){
                    vector< pair <double,int> > vect;
                    for( k=0;k<A[0].size();k++){
                        vect.push_back( make_pair(S[l][k],k) );
                    }
                    //sort(vect.begin(), vect.end());
                   double r=0.0;
                   for(int i=0;i<A[0].size();i++){
                        if(vect[i].first>=vect[o].first && i!=o){
                            r++;
                        }
                   }
                   r=(r-1)/(m-1);
                   rnk[l][o]=r;
                   while (!vect.empty()){vect.pop_back();}
            }
         }
    vector< pair <double,int> > vect2;
    m=A[0].size();
    double z=0;
    double r;
    /*r = (rand() % 1000) + 1;
    double prob[m];
    for(int i=0;i<m;i++){
        r = (rand() % 1000) + 1;
        prob[i]=r/1000;
    }*/
    for(int i=0;i<25;i++){
        for(int j=0;j<m;j++){
                z=z+rnk[i][j];
            }
        vect2.push_back(make_pair(z/m,i));
        z=0;
        }
    //sort(vect2.begin(), vect2.end());
    for(int j=0;j<25;j++){
        //fout<<vect2[j].first<<" "<<vect2[j].second<<endl;
        wil[j][t]=vect2[j].first;
       // cout<<wil[j][o]<<" "<<vect2[j].first<<endl;
    }
   // fout<<t<<" "<<endl;
    fin.close();
    int f=A.size();
    int g=A[0].size();
    for(int i=0;i<f;i++){
        while (!A[i].empty())
        {
            A[i].pop_back();}
    }
    A.clear();
    while (!vect2.empty())
      {vect2.pop_back();}
    while (!e.empty())
      {e.pop_back();}
    while (!row.empty())
      {row.pop_back();}
}
/*
for (int i=0;i<25;i++) {
  for(int j=0;j<25;j++){
        for(int k=0;k<5;k++){
                vector<double> p;
                if(wil[j][k]-wil[i][k]!=0){
                    p.push_back(wil[j][k]-wil[i][k]);
            }
        for(int l=0;l<p.size();l++){
            if(l!=(p.size()-1)){
                fout<<p[l]<<",";
            }else fout<<p[l];
        }
        fout<<endl;
        while (!p.empty())
      {p.pop_back();}
        }
  }
  }*/

for(int i=0;i<25;i++){
        for(int j=0;j<500;j++){
                //cout<<wil[i][j]<<endl;
                if(j!=499)fout<<wil[i][j]<<",";
                else fout<<wil[i][j];}
        fout<<endl;}
fout.close();
    return 0;
}
