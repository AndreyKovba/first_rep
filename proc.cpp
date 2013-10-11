#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int bykv_to_int(char a){
	int val = ( (int) a) - 48;
	if( val>9 ){
		switch ( a ){
			case 'a': case 'A':
				val=10;
			break;
			case 'b': case 'B':
				val=11;
			break;
			case 'c': case 'C':
				val=12;
			break;
			case 'd': case 'D':
				val=13;
			break;
			case 'e': case 'E':
				val=14;
			break;
			case 'f': case 'F':
				val=15;
			break;
		}
	}
	return val;
}


//int hex_to_dec(string hex){
int hex_to_dec(char *hex,int length){
	int dec=0;
	//int length=hex.size();
	for(int i=0; i<length; i++){
		dec*=16;
		dec+=bykv_to_int(hex[i]);
		//cout<<dec<<" ";
	}
	
	//cout<<dec<<"\n\n";
	return dec;
}


char* dec_to_hex(int dec){
	char *hex=new char[5];
	char cifer [16] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9', 'A','B','C','D','E','F'};
	int razr;
	
	int start=4096;

	for(int i=0;i<4; i++){
		razr=dec/start;
		hex[i]=cifer[razr];
		dec=dec-razr*start;
		start/=16;
		//cout<<razr<<"!!";
	}
	hex[4]=0;
	return hex;
}

/*
void echo_hex(int dec){
	char *res=new char[5];
	res= dec_to_hex(dec);
	for(int i=0; i<4;i++){
		cout<<res[i];
	}
}
*/




int main(){
	ifstream fin_conf("config.txt");
	ifstream fin_in("input.txt");
	ofstream fout("listing.txt");
	
	int op=0,i=0,p=0, pereh=0, ir=0,ind=0, ia=0, ron=0, ykkom=0, vib=0,sp=0,rez1=0;
	bool zapp=0,zam1=0,zam2=0,vzap1=0,chist=0,pysk=1, pr1=0,pr2=0,f=0;

	bool adrkom_prov,kom_prov,kop_prov,ind_prov,
		a_prov,ia_prov,sp_prov,sum_prov,
		przn_prov,rez1_prov,pr_prov;
	//int kop;
	string line;

	/**** schit inf o provodah ****/
    getline(fin_conf, line);
		adrkom_prov=(line[0]=='1');
    getline(fin_conf, line);
		kom_prov=(line[0]=='1');
	getline(fin_conf, line);
		kop_prov=(line[0]=='1');
	getline(fin_conf, line);
		ind_prov=(line[0]=='1');

	 getline(fin_conf, line);
		a_prov=(line[0]=='1');
    getline(fin_conf, line);
		ia_prov=(line[0]=='1');
	getline(fin_conf, line);
		sp_prov=(line[0]=='1');
	getline(fin_conf, line);
		sum_prov=(line[0]=='1');

	getline(fin_conf, line);
		przn_prov=(line[0]=='1');
    getline(fin_conf, line);
		rez1_prov=(line[0]=='1');
	getline(fin_conf, line);
		pr_prov=(line[0]=='1');





	int * pr=new int[2];//op*8+i*4+p;
	pr[0]=0;
	pr[1]=0;

	char *slovo=new char[4];
	char *result=new char[4];
	/*
	char **kop=new char*[32000];
	char **adr_str=new char*[32000];
	*/
	char *kop=new char[2];
	char *adr_str=new char[4];
	char *byte=new char[32000*6];
	for(int i=0; i<192000; i++){
		//kop[i]=new char[2];
		//adr_str[i]=new char[4];
		byte[i]=' ';
	}

	//string adr_str;
	int adr=0;

	int i_my=0;
	while(!fin_in.eof()){
		fin_in>>kop[0];
		fin_in>>kop[1];
		fin_in>>adr_str;
		
		byte[i_my*6+0]=kop[0];
		byte[i_my*6+1]=kop[1];
		for(int i=0; i<4;i++){
			byte[i_my*6+i+2]=adr_str[i];
		}
		i_my++;
		//cout<<"13";
	}


	for(int i=0; i<4;i++){
		adr_str[i]='0';
	}
	kop[0]='0';
	kop[1]='0';




	int prog_length=i_my*6;
	int pam_length=prog_length/2;
	
	int command_length=3;
	int length=4;
	int aly_enter;
	while(pysk){
		//fin_in>>kop[0];
		//fin_in>>kop[1];
		//fin_in>>adr_str;
		//adr=hex_to_dec(adr_str[ykkom],length);
		
		//adr=ykkom/3;
		if(adrkom_prov){
			adr=ykkom;
		}

		if(kom_prov){
			kop[0]=byte[adr*2];
			kop[1]=byte[adr*2+1];
		}

		/*for(int i=0;i<62;i++){
			//cout<<adr*2<<"\n";
			cout<<byte[i]<<"\n";
		}
		/*
		cout<<kop[0]<<kop[1]<<"\n";
		for(int i=2;i<6;i++){
			cout<<byte[adr*2+i]<<" ";
		}
		*/
		/***deccom***/
		if(kop_prov){
			switch ( kop[0] ) {
				case '0':
					switch ( kop[1] ) {
						case '0':
							i=1;
							p=0;
							op=0;
							pereh=0;
						break;

						case '2':
							i=1;
							p=2;
							op=0;
							pereh=0;
						break;
					}
				break;
				case '1':
					switch ( kop[1] ) {
						case '1':
							i=0;
							p=1;
							op=1;
							pereh=0;
							//cout<<"!";
						break;

						case '5':
							i=1;
							p=1;
							op=1;
							pereh=0;
						break;
					}
				break;

				case '2':
					switch ( kop[1] ) {
						case '1':
							i=0;
							p=1;
							op=2;
							pereh=0;
						break;

						case '5':
							i=1;
							p=1;
							op=2;
							pereh=0;
						break;
					}
				break;

				case '3':
					if( kop[1]=='1'){
						i=0;
						p=1;
						op=3;
						pereh=0;
					}
				break;

				case 'f':case 'F':
					switch ( kop[1] ) {
						case '0':
							p=4;
							op=15;
							if(pr1){
								pereh=1;
							}
							else{
								pereh=0;
							}
						break;

						case '1':
							p=4;
							op=15;
							pereh=0;
							if(pr2){
								pereh=1;
							}
							else{
								pereh=0;
							}
						break;

						case '4':
							p=4;
							op=15;
							if(!f){
								pereh=1;
							}
							else{
								pereh=0;
							}
						break;

						case '5':
							p=4;
							op=15;
							if(f){
								pereh=1;
							}
							else{
								pereh=0;
							}
						break;

						case 'e': case 'E':
							p=4;
							op=15;
							pereh=1;
						break;

						case 'f': case 'F':
							p=4;
							op=15;
							pereh=0;
							pysk=0;
						break;
					}
				break;
			}
		}
		/************/
		zapp=(p==0);
		zam1=(p==1);
		zam2=(p!=3);
		vzap1=(p==3);
		vib=i;
		chist=!(p==2 || p==3);


		if(kom_prov){
			for(int i=0;i<4;i++){
				adr_str[i]=byte[adr*2+i+2];
			}
		}

		if(ind_prov){
			if(a_prov){
				ia=ind+hex_to_dec(adr_str,length);
			}
			else{
				ia=ind;
			}
		}
		else{
			if(a_prov){
				ia=hex_to_dec(adr_str,length);
			}
			else{
				ia=0;
			}
		}




		if(pereh==1){
			ykkom=ia;
			//cout<<"%"<<pr1;
		}
		else{
			if(adrkom_prov){
				ykkom+=command_length;
			}
		}

		
		for(int i=0;i<4;i++){			
			slovo[i]=byte[2*ia+i];
			
			//cout<<slovo[i];
			//cout<<byte[i]<<" ";
		}
		sp=hex_to_dec(slovo,length);
		
		
		aly_enter=0;
		
		if(vib==2){
			//nebivaet
		}
		else{
			if(vib==1){
				if( ia_prov){
					aly_enter=ia;
				}
			}
			else{
				if(sp_prov){
					aly_enter=sp;
				}
			}
		}
		//cout<<vib<<"  "<<sp<<"\n";
		
		//cout<<op<<"!";
		if(rez1_prov){
			switch ( op ) {
				case 0:
					if(sum_prov){
						rez1=ron;
					}
					else{
						rez1=0;
					}
					/*
					result=dec_to_hex(rez1);
				
					for(int i=0; i<4; i++){
						byte[aly_enter*2+i]=result[i];
					}
					if(aly_enter*2+3>prog_length){
						prog_length=aly_enter*2+3;
					}
					*/
			
				break;

				case 1:
					rez1=aly_enter;
				break;

				case 2:
					if(sum_prov){
						rez1=ron+aly_enter;
					}
					else{
						rez1=aly_enter;
					}
					//ron=rez1;
				break;

				case 3:
					if(sum_prov){
						rez1=ron-aly_enter;
					}
					else{
						rez1=-aly_enter;
					}
					//ron=rez1;
				break;

				case 15:
					rez1=aly_enter;
				break;
			}
		}
		else{
			rez1=0;
		}



		
		if(zam2){
			if(chist==1 || !rez1_prov){
				ir=0;
			}
			else if(chist==0){
				ir=rez1;
				//cout<<"!!"<<rez1<<"!";
			}
		}

		if(zam1){
			if(rez1_prov){
				ron=rez1;
			}

			if(pr_prov){
				
				if(ron==0){
					pr1=1;
				}
				else{
					pr1=0;
				}

				if(ron>0){
					pr2=1;
				}
				else{
					pr2=0;
				}

				
			}
		}
		//cout<<rez1_prov<<"\n";


		if(zapp){
			result=dec_to_hex(rez1);
				
				for(int i=0; i<4; i++){
					byte[ia*2+i]=result[i];
				}
				if(aly_enter*2+3>prog_length){
					prog_length=ia*2+3;
				}
		}
		//cout<<rez1<<"  ";

		fout<<"\nRON_SYM: "<<ron<<"\nRON_PR: "<<pr1<<pr2;
		fout<<"\nYKKOM: "<<ykkom<<"\nIR: "<<ind<<"\nIA:    "<<ia<<"\nSP: "<<sp<<"\n";
		//fout<<chist<<"\n";

		/*cout<<"\nRON_SYM: "<<ron<<"\nRON_PR: "<<pr1<<pr2;
		cout<<"\nYKKOM: "<<ykkom<<"\nIR: "<<ind<<"\nIA:    "<<ia<<"\nSP: "<<sp<<"\n";
		*/

		pam_length=prog_length/2;
		for(int i=0;i<pam_length;i++){
			fout<<byte[2*i]<<byte[2*i+1]<<" ";
		}
		fout<<"\n";
	}

	/*
	prog_length/=2;
	for(int i=0;i<prog_length;i++){
		//cout<<byte[2*i]<<byte[2*i+1]<<" ";
	}
	*/
	//cout<<ron;
	//string str="3addd";
	//cout<<kop_pre<<"   "<<kop_pre.size();
	//cout<<kop;

	return 0;
}