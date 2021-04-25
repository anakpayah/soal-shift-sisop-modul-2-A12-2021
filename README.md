# soal-shift-sisop-modul-2-A12-2021
Repo github soal shift modul 2 sisop semester genap tahun 2021

<hr>

## Soal nomor 1
### Penjelasan Soal
Pada soal ini kita diminta untuk membuat 3 folder dengan nama "Musyik", "Fylm", dan "Pyoto". Kemudian kita mendownload musik, film, dan link dari link untuk di-extract dan dipindahkan ke folder yang dibuat. Semua hal tersebut dilakukan 6 jam sebelum tanggal 9 April pukul 22.22 WIB dan pada waktu 22.22 semua folder akan dizip dengan nama "Lopyu_Stevany.zip".
### Penjelasan kode tanpa daemon
```c
int main() {
    pid_t child_id;
    int status;
    ...
    ...
    for(int i=0; i<14; ++i){
        while ((wait(&status)) > 0);
        child_id = fork();

        if (child_id < 0) {
            exit(EXIT_FAILURE); 
        }

        if (child_id == 0) {
            execv(path[i][0], &argv[i][0]);
        } 
    }
  return 0;
}
```
Untuk melakukan perintah linux menggunakan c, kita menggunakan execv yang isinya adalah path dari perintah yang ingin dinginkan dan perintahnya tersebut. Pada program ini fork() harus digunakan untuk memanggil execv beberapa kali dimana child process akan menjalankan execv sedangkan parent process melakukan spawning process. Berikut adalah isi dari argv[][] dan path[][].

```c
    char *argv[][10] = {  {"mkdir", "Musyik", NULL},
                            {"mkdir", "Fylm", NULL},
                            {"mkdir", "Pyoto", NULL},
                            {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "-O", "Foto.ext", NULL},
                            {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik.ext", NULL},
                            {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "-O", "Film.ext", NULL},
                            {"unzip", "*.ext", NULL} ,
                            {"cp", "-r", "FOTO/.", "Pyoto", NULL},
                            {"cp", "-r", "MUSIK/.", "Musyik", NULL},
                            {"cp", "-r", "FILM/.", "Fylm", NULL},
                            {"rm", "Foto.ext", "Musik.ext", "Film.ext", NULL},
                            {"rm", "-r", "FOTO", "MUSIK", "FILM", NULL},
                            {"zip", "-r", "Lopyu_Stevany.zip", "Fylm", "Musyik", "Pyoto", NULL},
                            {"rm", "-r", "Fylm", "Musyik", "Pyoto", NULL} };
    char *path[][2] = {   {"/bin/mkdir"},
                            {"/bin/mkdir"},
                            {"/bin/mkdir"},
                            {"/usr/bin/wget"},
                            {"/usr/bin/wget"},
                            {"/usr/bin/wget"},
                            {"/usr/bin/unzip"}, 
                            {"/usr/bin/cp"},
                            {"/usr/bin/cp"},
                            {"/usr/bin/cp"},
                            {"/usr/bin/rm"},
                            {"/usr/bin/rm"},
                            {"/usr/bin/zip"},
                            {"/usr/bin/rm"} };
```
3 baris pertama akan membuat folder dengan nama "Musyik", "Fylm", dan "Pyoto" menggunakan mkdir. Baris 4-6 mendownload file Foto, Musik, dan Film dalam format .ext dari link menggunakan wget. Baris 7 meng-unzip semua file dengan ekstensi .ext. Baris 8-10 meng-copy isi dari file Foto, Musik, dan Film ke dalam folder yang telah dibuat. Baris 13 akan membuat zip bernama "Lopyu_Stevany.zip" yang isinya adalah folder "Fylm", "Musyik", dan "Pyoto" yang sudah diisi dengan file-file yang telah didownload. Baris 14 akan menghapus folder "Fylm", "Musyik", dan "Pyoto".

### Screenshot Output
![image](https://user-images.githubusercontent.com/7587945/115997477-71dc9800-a60d-11eb-8dab-130484fe2452.png)
![image](https://user-images.githubusercontent.com/7587945/115997493-815be100-a60d-11eb-96a2-3a916eee9bf0.png)
![image](https://user-images.githubusercontent.com/7587945/115997524-920c5700-a60d-11eb-88a7-6fe2a325c9e3.png)
![image](https://user-images.githubusercontent.com/7587945/115997546-a6505400-a60d-11eb-9fb8-baf44e4146d6.png)
![image](https://user-images.githubusercontent.com/7587945/115997568-b5cf9d00-a60d-11eb-8c65-0edb1cd46368.png)

### Penjelasan kode tanpa daemon (masih error)
```c
int main() {
  pid_t pid, sid;     
  pid = fork();  

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/home/kelvin/Documents/soal-shift-sisop-modul-2-A12-2021-main/soal1")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while (1) {
    pid_t child_id;
    int status;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    char *argv[][10] = {  {"mkdir", "Musyik", NULL},
                            {"mkdir", "Fylm", NULL},
                            {"mkdir", "Pyoto", NULL},
                            {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "-O", "Foto.ext", NULL},
                            {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik.ext", NULL},
                            {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "-O", "Film.ext", NULL},
                            {"unzip", "*.ext", NULL} ,
                            {"cp", "-r", "FOTO/.", "Pyoto", NULL},
                            {"cp", "-r", "MUSIK/.", "Musyik", NULL},
                            {"cp", "-r", "FILM/.", "Fylm", NULL},
                            {"rm", "Foto.ext", "Musik.ext", "Film.ext", NULL},
                            {"rm", "-r", "FOTO", "MUSIK", "FILM", NULL},
                            {"zip", "-r", "Lopyu_Stevany.zip", "Fylm", "Musyik", "Pyoto", NULL},
                            {"rm", "-r", "Fylm", "Musyik", "Pyoto", NULL} };
    char *path[][2] = {   {"/bin/mkdir"},
                            {"/bin/mkdir"},
                            {"/bin/mkdir"},
                            {"/usr/bin/wget"},
                            {"/usr/bin/wget"},
                            {"/usr/bin/wget"},
                            {"/usr/bin/unzip"}, 
                            {"/usr/bin/cp"},
                            {"/usr/bin/cp"},
                            {"/usr/bin/cp"},
                            {"/usr/bin/rm"},
                            {"/usr/bin/rm"},
                            {"/usr/bin/zip"},
                            {"/usr/bin/rm"} };

    if(tm.tm_mon + 1 == 4 && tm.tm_mday == 9 && tm.tm_hour == 16 && tm.tm_min == 22){
        for(int i=0; i<12; ++i){
            while ((wait(&status)) > 0);
            child_id = fork();

            if (child_id < 0) {
                exit(EXIT_FAILURE); 
            }

            if (child_id == 0) {
                execv(path[i][0], &argv[i][0]);
            } 
        }
        sleep(60);
    }
    if(tm.tm_mon + 1 == 4 && tm.tm_mday == 9 && tm.tm_hour == 22 && tm.tm_min == 22){
        for(int i=12; i<14; ++i){
            while ((wait(&status)) > 0);
            child_id = fork();

            if (child_id < 0) {
                exit(EXIT_FAILURE); 
            }

            if (child_id == 0) {
                execv(path[i][0], &argv[i][0]);
            }
        }   
        break;
    }

    sleep(10);
  }

  return 0;
}
```
supaya perintah berjalan secara otomatis pada suatu waktu, kita perlu menggunakan daemon supaya program berjalan dibackground dan perintah akan dilaksanakan saat waktunya telah datang. Kita menggunakan template daemon yang terdapat pada daemon. Disini `time_t t = time(NULL);` dan `struct tm tm = *localtime(&t);` digunakan untuk mendapatkan waktu yang akan tersimpan di tm.tm_mon untuk bulan, tm.tm_mday untuk hari, tm.tm_hour untuk jam dan tm.tm_min untuk menit. Program akan jalan dan tidak melakukan apa-apa jika waktunya belum 16:22 atau 22:22 tanggal 9 April dan sleep selama 10 detik, kemudian program akan loop. Jika sudah jam 16:22 tanggal 9 April maka program akan menjalankan perintah `{"mkdir", "Musyik", NULL}` sampai perintah `{"rm", "-r", "FOTO", "MUSIK", "FILM", NULL}` dan sleep selama 60 detik supaya saat loop akan lewat 1 menit sehingga tidak lagi jam 16:22 dan program tidak akan menjalankan perintah tersebut lagi. Program akan melaksanakan perintah yang tersisa jika sudah jam 22:22 tanggal 9 April.
#### Kendala
program yang menggunakan daemon ini mengalami kendala dimana perintah cp yang mengcopy file yang didownload ke folder "Pyoto", "Musyik", dan "Fylm" tidak berjalan sehingga pada akhirnya isi dari 3 folder tersebut akan kosong.

### Screenshot Output
Screenshot setelah 16:22 tanggal 9 April
![image](https://user-images.githubusercontent.com/7587945/115998181-427b5a80-a610-11eb-9e7e-914964972af9.png)
![image](https://user-images.githubusercontent.com/7587945/115998191-49a26880-a610-11eb-82e6-64b35d704b76.png)
![image](https://user-images.githubusercontent.com/7587945/115998207-5aeb7500-a610-11eb-8ddf-7cc645e6338f.png)


Screenshot setelah 22:22 tanggal 9 April
![image](https://user-images.githubusercontent.com/7587945/115998237-82424200-a610-11eb-88e8-1c9d881ab557.png)
![image](https://user-images.githubusercontent.com/7587945/115998282-bd447580-a610-11eb-9db0-3d1ee33b108f.png)
![image](https://user-images.githubusercontent.com/7587945/115998288-c6354700-a610-11eb-96e6-9a5711644af5.png)
![image](https://user-images.githubusercontent.com/7587945/115998245-8c644080-a610-11eb-9ee1-0c03f4badf7c.png)
![image](https://user-images.githubusercontent.com/7587945/115998272-af8ef000-a610-11eb-8447-d72145f05db3.png)

<hr>

## Soal nomor 2


<hr>

## Soal nomor 3
### Penjelasan
Terdapat seorang yang bernama Ranora, dia disuruh pembimbingnya untuk membuat program  berbahasa c yang dapat mendownload batch gambar setiap 40 detik. Pada setiap batch tersebut, batch akan mendownload 1 gambar setiap 5 detik hingga 10 kali. Jika batch tersebut berhasil mendownload 10 gambar, maka gambar - gambar tersebut akan dijadikan dalam satu file .zip dengan format nama tertentu. Selanjutnya Ranora diperintahkan untuk membuat suatu executable shell dengan nama killer.sh yang digunakan untuk menghentikan proses program .c yang dibuat sebelumnya. Namun Killer.sh ini bekerja sesuai dengan argumen saat menjalankan program .c, dan masing - masing argumen tersebut memiliki sifat masing - masing.  
### Soal 3A.
pada soal 3A ini kita disuruh untuk membuat sebuah directory baru dengnan format nama tertentu sesuai dengan format waktu directory tersebut dibuat.
```c
  char timeForm[20];
	time_t sekarang = time(NULL);
	struct tm *waktu = localtime(&sekarang); 
		
	strftime (timeForm, sizeof(timeForm), "%Y-%m-%d_%H:%M:%S", waktu);
    	
	pid_t child_id;
	child_id = fork();
		
	if (child_id < 0)
		exit (EXIT_FAILURE);
	if (child_id == 0) {
		char *argv[] = {"mkdir", timeForm, NULL};
		execv ("/bin/mkdir", argv);
	}
```  
potongan kode tersebut menjelaskan mengambil format waktu dan dimasukan ke variabel `timeForm` yaitu variabel yang berisi format timestamp [YYYY-mm-dd_HH:ii:ss].  
formatnya sendiri yaitu mengambil waktu dari device menggunakan fungsi `localtime()`. lalu membuat argumen mkdir di terminalnya menggunakan fungsi `execv` dan membuat sebuah directory baru bernama timeForm yang sesuai dengan format timestamp yang diinginkan. 
#### Kendala  
tidak ada kendala dalam pengerjaan soal ini.  

### soal 3B.
Membuat process yang dapat mendownload 1 gambar setiap 5 detik sebanyak 10 kali yang didownload dari https://picsum.photos/. Gambar - gambar ini akan di simpan pada direktori yang telah dibuat sebelumnya dengan nama file dengan format tertentu sesuai timestamp. Gambar tersebut berbentuk persegi dengan ukuran (n%1000) + 50 pixel dimana n adalah detik Epoch Unix.  
```c
void downloadPics(char dirName[]) {
	int i, maxPics = 10;
	for (i=0 ; i<maxPics ; i++) {
	
		pid_t child_id;
		child_id = fork();
				
		char downLink[1000], link[] = "https://picsum.photos/";		
		char fileName[20];
		time_t sekarang = time(NULL);
		int now = (int)sekarang;
		int size = (now%1000)+50;
		struct tm *waktu = localtime(&sekarang); 
		
		strftime (fileName, sizeof(fileName), "%Y-%m-%d_%H:%M:%S", waktu);		
		sprintf(downLink, "%s%d", link, size);
		
		char filePath[50];
		sprintf (filePath, "%s%c%s%s", dirName, '/', fileName, ".jpeg");
		
		if (child_id < 0)
        	exit (EXIT_FAILURE);
    		if (child_id == 0) {
        		char *argv[] = {"wget", "-q", "--no-check-certificate", downLink, "-O", filePath, NULL};
        		execv ("/bin/wget", argv);
    		}
    		sleep(5);		
	}
	makeText(dirName);
	zipping(dirName);
	return;
}
```  
potongan kode diatas merupakan fungsi untuk mendownload gambarnya. menggunakan perulangan for sampai 10. untuk penamaannya sendiri sama seperti pembuatan nama directory sebelumnya yaitu mengambil nilai dari fungsi `time(NULL)` masuk ke variabel sekarang. untuk menggantinya menjadi format string yang sesuai yang akan digunakan menjadi nama nantinya masuk ke tipe data `struct tm` yaitu bentuk dari format waktu dengan variabel bernama `waktu` yang nilainya didapat dari fungsi `localtime()`.  
untuk donwload linknya, bila ingin susuai dengan ukuran yang diinginkan yaitu cukup menambahkan nilai integer setelah link tersebut. namun kita disuruh untuk memberikan nilai ukurannya berupa (n % 1000) + 50 dengan n berupa nilai Epoch Unix. nilai tersebut dalam code saya yaitu dalam variabel `now` yang berisikan epoch unix dari variabel `sekarang` karena itu diambil dari fungsi `time(NULL)`.  
lalu foto yang didownload tadi dimasukan kedalam filepath sesuai dengan nama direktori sebelumnya, saya menggunaan fungsi `sprintf()`.  
menggunakan fork untuk bisa melakukan tugas lebih dari satu atau bersamaan menggunkan argumen dan fungsi `execv`. fork tersebut akan di jeda denngan waktu 5 detik tiap pendownload annya menggunakan fungsi `sleep(5)`.  

### kendala
untuk kendalanya saya (Afifan) yang mengerjakan salah paham terkait deng ukuran dari gambar yang di download. saya berpikir bahwasannya nilai angka setelah link (ex : "https://picsum.photos/780") merupakan id dari gambar tersebut. setelah saya coba di web, nilai tersebut bukanlah menunjukan id dari gambar melainkan ukuran gambar tersebut. pada kodingan diatas pada varaibel `size` sebelumnya adalah variabel `picsID` dikarenakan saya salah paham sebelumnya.  
perubahan(revisi) hanya berupa pergantian nama variabel agar tidak ambigu dan salah paham saja.  

## Soal 3C.
Membuat fungsi yang dapat menyimpan suatu file status.txt pada direktori sebelumnya yang berisi pesan “Download Success” yang di-encrypt menggunakan Caesar Cypher 5 Shift. Setelah 10 gambar .jpg dan satu file status.txt berhasil disimpan pada direktori, selanjutnya adalah menyimpan seluruh file pada direktori ini pada suatu file .zip dan menghapus seluruh isi direktori dan direktori itu sendiri.  
menggunkan fungsi chiper sederhana yang didapat dari internet, fungsi kode sebagai berikut.  
```c
void caesarChiper(char text[]) {
	char string[]="Download Success";
	int i;
	for (i=0 ; string[i] != '\0'; i++) {
		if(string[i] == ' ') text[i] = ' ';
		else if(string[i] >= 'a' && string[i] <= 'z'){
			string[i] += 5;			
			if(string[i] > 'z'){
				string[i] = string[i] - 'z' + 'a' - 1;
			}			
			text[i] = string[i];
		}
		else if(string[i] >= 'A' && string[i] <= 'Z'){
			string[i] += 5;			
			if(string[i] > 'Z'){
				string[i] = string[i] - 'Z' + 'A' - 1;
			}			
			text[i] = string[i];
		}	
	}
	text[i++]='\0';
	return;
}
```  
fungsi untuk merubah text mennjadi chiper shift 5+. hasil ext sebagai berikut:  
```
Itbsqtfi Xzhhjxx
```  
lalu directory beserta isinya akan di zip dan tidak menyisahkan sisa (keseluruhan di zip tanpa di copy). potongan code sebagai berikut :  
```c
void zipping(char dirName[]) {
	char zipName[50];
	sprintf (zipName, "%s%s", dirName, ".zip");


	char *argv[] = {"zip", "-rmqq", zipName, dirName, NULL};
	execv("/bin/zip", argv);
	
	return;
}
```  
menggunakan argumen dan fungsi execv. saya menggunakan `-rm` dikarenakan stelah di zip, nantinya hanya akan menyisahkan file zip saja. penambahan `qq` dibelakang hanya untuk menghilangkan log proses di terminal saja.  

### kendala
tidak ada kendala dalam pengerjaan soal ini.  

## Soal 3D.
Membuat suatu fungsi yang dapat membuat suatu program bash "killer.sh" yang dapat digunakan untuk melakukan termination pada process utama dan process child yang berjalan dan menghapus dirinya sendiri setelah operasi selesai. kode sebagai berikut :  
```c
void killer(int pid, int mode) {
	FILE *killer = fopen("killer.sh", "w");
	char exe[1001];
	if (mode == 0) {
		sprintf (exe, "%s", "#!/bin/bash\npkill -9 soal3\nrm killer.sh");
		fprintf(killer, "%s", exe);
		fclose(killer);
		return;
	}
	else if (mode == 1) {
		sprintf (exe, "%s%d%s", "#!/bin/bash\nkill %d", pid, "\nrm killer.sh");
		fprintf(killer, "%s", exe);
		fclose(killer);
		return;
	}
	printf ("gagal");
	return;
}
```  
membuat fungsi `killer()` yang digunakan untuk membuat file "killer.sh" file yang berisi command untuk menjalankan program kill sesuai mode yang diinginkan dan akan ter-elimintae sendiri setelah program tersebut selesai dijalankan.  
untuk membuat file program tersebut menggunkanan fungsi `fopen()`, `fprintf()` dan `fclose()`.
pid yang diambil didapat dari `getpid()` pada fungsi program utama.  
```c
int main(int argc, char **argv) {
	int pid = (int)getpid();
	
	if (strcmp (argv[1], "-z")== 0) killer(pid, 0);
	
	else if (strcmp (argv[1], "-x")== 0) killer(pid, 1);
	
	else 
		return 0;	
	
	while (1) makeDirectory();

	return 0;
}
```  
### kendala
tidak ada kendala dalam pengerjaan soal ini.  

## soal 3E.  
Menambahkan suatu argument pada program .c utama dijalankan yang masing - masing argument tersebut akan berpengaruh pada "killer.sh" yang akan dieksekusi.
```c
int main(int argc, char **argv) {
	int pid = (int)getpid();
	
	if (strcmp (argv[1], "-z")== 0) killer(pid, 0);
	
	else if (strcmp (argv[1], "-x")== 0) killer(pid, 1);
	
	else 
		return 0;	
	
	while (1) makeDirectory();

	return 0;
}

void killer(int pid, int mode) {
	FILE *killer = fopen("killer.sh", "w");
	char exe[1001];
	if (mode == 0) {
		sprintf (exe, "%s", "#!/bin/bash\npkill -9 soal3\nrm killer.sh");
		fprintf(killer, "%s", exe);
		fclose(killer);
		return;
	}
	else if (mode == 1) {
		sprintf (exe, "%s%d%s", "#!/bin/bash\nkill ", pid, "\nrm killer.sh");
		fprintf(killer, "%s", exe);
		fclose(killer);
		return;
	}
	printf ("gagal");
	return;
}
```
penambahan argumen khusus hanya menambahkan argumen `argc` dan `argv` pada fungsi mainnya. unutk pembuatannya tegantung argumen yang akan diinput nantinya.  
bila menggunakan `-z` : menggunkan mode 0, tidak perlu menggunkan pid yang didapat, cukup melakukan `pkill -9 [namasoal]` untuk isinya, lalu menggunakan `rm killer.sh`. opreasi program tersebut akan menghentikan seluruh program yang dijalankan. eksekusi dengan mengetik pada terminal `bash killer.sh`
bila menggunakan `-x` : menggunkan mode 1, pid digunakan untuk menghentikan program parentnya dengan format `kill [pid]` yang hanya mengekill parentnya saja. bila mengeksekusi menggunakan `bash killer.sh` di terminal. program lanjutan akan terhenti dan hanya menyishakan program anaknya saja yang masih berjalan hingga selesainya program tersebut.  
### kendala
kendala yang dialami hanya typo minor saja pada mode 1 pada line sebagai berikut :  
```sprintf (exe, "%s%d%s", "#!/bin/bash\nkill %d", pid, "\nrm killer.sh");```  
dilihat setelah kill ada character berupa `%d` yang tidak memiliki makna apa-apa dan menyebabkan error ketika program `killer.sh` dijalankan. revisi yang dilakukan menghapus karakter tersebut.  
```sprintf (exe, "%s%d%s", "#!/bin/bash\nkill ", pid, "\nrm killer.sh");```

##### berikut adalah isi `killer.sh` ketika memakai command -z :  
![image](https://user-images.githubusercontent.com/75328763/115996182-73579180-a608-11eb-86fb-46c8a10e7bd2.png)  
##### hasil isi ketika killer.sh dijalankan ketika belum selesainya program killr.sh dari command -z
![image](https://user-images.githubusercontent.com/75328763/115996361-1c9e8780-a609-11eb-9980-572f951a6c48.png)  
program akan terhenti semuanya, tidak ada kelanjutan program dari parent maupun child lainnya.  
##### berikut adalah isi `killer.sh` ketika memakai command  -x



