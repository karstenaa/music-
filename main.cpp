#include <stdio.h>
#include <windows.h>
#include <dirent.h>
#include <string>
#include <vector>
#include <conio.h>
#include <algorithm>
using namespace std;
vector <string> v;
int main(){
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir ("music")) != NULL) {
	  /* print all the files and directories within directory */
	  while ((ent = readdir (dir)) != NULL) {
	  	string s=ent->d_name;
	  	if(s=="." || s=="..")continue;
	  	v.push_back(s);
	    //printf ("%s\n", s.c_str());
	  }
	  closedir (dir);
	  	while(1){
	  		char input= getch();
	  		printf("%c ",input);
	  		int index = min((input-'a')%(int)v.size(),25);
	  		string note = string("./music/") + v[index];
	  		printf("%s\n",v[index].c_str());
			PlaySound(note.c_str(), NULL, SND_ASYNC);
		}
	} else {
	  /* could not open directory */
	  perror ("");
	  return EXIT_FAILURE;
	}

	return 0;
}
