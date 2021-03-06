#include<iostream>

int Estediaempezoelciclo(int ciclo){
	if(ciclo%400!=0){
		return (ciclo+(ciclo/4)-(ciclo/100)+(ciclo/400)+1)%7;
	}
	return (ciclo+(ciclo/4)-(ciclo/100)+(ciclo/400))%7;
}

int Estediaempezoelmes(int dias[12],int diaD,int mes){
	for(int i=0;i<mes-1;++i){
		diaD=diaD+dias[i];
	}
	if(diaD%7){
		return diaD%7;
	}
	return 7;
}
bool Vamoconlosbisiestos(int ciclo){
	if((ciclo%4!=0)||(ciclo%100==0&ciclo%400!=0)){
		return false;
	}
	return true;
}

void ImprimirCalendario(int Ndias,int dias[12],int diaD,int mes){
	int Z=Estediaempezoelmes(dias,diaD,mes);
	std::cout<<Z<<std::endl;
	std::cout<<"Dom Lun Mar Mie Jue Vie Sab"<<std::endl;
	for(int j=1;j<Z;++j){
		std::cout<<"    ";
	}
	for(int i=1;i<=Ndias;++i){
		printf("%3d ",i);
		if(Z%7==0){
			std::cout<<'\n';
		}
		Z++;
	}
}

int main(){
	int ciclo;
	int mes;
	int diaD;
	int diasdelmes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	std::string meses[12]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
	std::cout<<"Ciclo: "<<std::endl;std::cin>>ciclo;
	std::cout<<"Mes: "<<std::endl;std::cin>>mes;
	if(Vamoconlosbisiestos(ciclo)){
		diasdelmes[1]+=1;
		std::cout<<"Bisiesto"<<std::endl;
	}
	diaD=Estediaempezoelciclo(ciclo);
	std::cout<<meses[mes-1]<<std::endl;
	ImprimirCalendario(diasdelmes[mes-1],diasdelmes,diaD,mes);
}
