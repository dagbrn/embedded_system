# Pedestrian Traffic Light
Program ini merupakan simulasi traffic light untuk penyeberangan pejalan kaki menggunakan Arduino Uno di Tinkercad. Sistem memakai satu lampu lalu lintas kendaraan dan dua tombol penyeberangan untuk mengaktifkan fase aman bagi pejalan kaki.


## Cara Kerja Sistem
- Saat awal sistem dijalankan, **lampu kendaraan hijau** menyala dan **lampu pejalan kaki merah** aktif sebagai kondisi default.
- Sistem menunggu **tombol penyeberangan** ditekan. Kedua tombol yang tersedia memicu alur penyeberangan yang sama melalui interrupt.
- Saat tombol ditekan, **lampu kendaraan berubah merah** agar lalu lintas berhenti.
- Setelah itu, **lampu pejalan kaki hijau** menyala selama **5 detik** untuk memberi waktu menyeberang.
- Ketika waktu selesai, **lampu pejalan kaki kembali merah**.
- Sebagai transisi kembali ke kondisi normal, **lampu kendaraan kuning berkedip 3 kali** dengan total kedipan 2 detik.
- Setelah rangkaian selesai, sistem kembali ke **kondisi awal** dan siap menerima penekanan tombol berikutnya.

## Demo
Uploading Screen Recording 2026-04-05 192453.mp4…






## Link Tinkercad
https://www.tinkercad.com/things/1XYaTHxcdo3-pedestriantraffic-light?sharecode=JvJdaCQrqQinZCQK563Qtl1HJzr6HIiEq3mz-E3abYc
