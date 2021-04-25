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
Membuat process yang dapat mendownload 1 gambar setiap 5 detik sebanyak 10 kali yang didownload dari ~https://picsum.photos/~. Gambar - gambar ini akan di simpan pada direktori yang telah dibuat sebelumnya dengan nama file dengan format tertentu sesuai timestamp. Gambar tersebut berbentuk persegi dengan ukuran (n%1000) + 50 pixel dimana n adalah detik Epoch Unix.

