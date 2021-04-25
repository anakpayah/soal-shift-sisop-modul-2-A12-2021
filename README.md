# soal-shift-sisop-modul-2-A12-2021
Repo github soal shift modul 2 sisop semester genap tahun 2021

<hr>

## Soal nomor 1


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



