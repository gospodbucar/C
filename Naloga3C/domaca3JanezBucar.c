#include <stdio.h>//JANEZ BUCAR 35160122
#include <sys/types.h> //fork()
#include <unistd.h>  //getpid(),getuid(), getppid()
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/wait.h>

int main ()
{ 
	//nov file pointer za delo z datotekami
	FILE * datoteka;
	FILE * dat = stdout; // da zapise v datoteko pred funkcijo sleep()

	//shranim v rezultati3.txt, zaradi "a" se nadaljuje shranjevanje, če bi želel na novo bi dal "w"
	datoteka = fopen("rezultati3.txt", "a");
	
	//zapis v datoteko pid in uid
	fprintf(datoteka, "\nzacetek izvajanja programa.PID izvajanja procesa je %d.UID procesa je %d.\n",getpid(), getuid());
	
	//zapremo datoteko
	fclose(datoteka);
	


	
	//z fork ustvarim nov child proces
	int pid = fork();
	int status; // za waitpid()
	if(pid == 0) // če fork vrne 0 pomeni da se izvaja child process
	{
	//znova odpremo dat za zapisovanje
		datoteka = fopen("rezultati3.txt", "a");
		dat = fopen("rezultati3.txt", "a");
		fprintf(dat,"Proces otrok je bil ustvarjen. PID procesa otrok je %d.PPID starsevskega procesa je %d\n", getpid(), getppid()); //getppid() dobi pid parent iz child

		fclose(dat);
	

	fprintf(datoteka, "Otrok zacenja z izvajanjem programa ls\n");
		
	sleep(10); //program se zaustavi za 10 sekund da se zgodi zgornji ukaz
	DIR *d; 
  	struct dirent *dir; // pointer za dostop do imenika
  	d = opendir(".");	//opendir() vrne pointer DIR typa
  	if (d) {
    		while ((dir = readdir(d)) != NULL) { // če se je povezal z imenikom nam vrača imena datotek oz ls dokler ne gre čez vse
      			fprintf(datoteka, "%s\n", dir->d_name);
    						}
    			closedir(d); // zaprem dir
  		}

		fclose(datoteka);
		
		
		exit(EXIT_SUCCESS); 
	}
	
	waitpid(pid, &status, 0); // počaka da se child konča preden se zacne izvajati parent process
	if (WIFSIGNALED(status)){printf("error");}
	else if (WEXITSTATUS(status)){printf("normalno");}
	
	
	
	//če fork vrne več od 0 pomeni da izvrsuje parent process
	else if (pid > 0){

	datoteka = fopen("rezultati3.txt", "a");
	
	// int pid = fork () ---tukaj je "pid of child" v sami spremenljivki pid in ga tako klicem iz parenta
	fprintf(datoteka, "PID Otroškega procesa, ki se je končal je, %d\n", pid);
	
	//vnesemo poljubno pozitivno stevilo.
	printf("Vnesite poljubno celostevilsko pozitivno stevilo\t");
	
	int n;
	unsigned long long fakulteta = 1; // unsigned long long ne more shranit negativnega stevila
	scanf("%d", &n);
	//preveri ali je pozitivno oz manjse kot 1
	if( n < 1 )
	{
		printf("število ni pozitivno");
	}
	
	else 
	{
		for(int i = 1; i <= n; ++i){
			
			fakulteta *=i; // dokler ni i ki se povečuje ya 1 enak ali večji n se fakulteta množi z i

		}
		
		fprintf(datoteka, "Fakulteta stevila %d je: %lld.\n\n\n\n", n, fakulteta); // izpis %lld je unsigned long long
	}
	
	
	fclose(datoteka);
	
	
	}
	
	//če se child proces ne ustvari javi napako
	else{
	
	printf("ustvarjanje child procesa ni uspelo");
	return 1;
	}
	
	return 0;
	

}
