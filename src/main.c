#include<stdio.h>
#include "../include/pages.h"
#define LOGOUT -99
#define BACK -1

int main() {
  char *quests[3][10] = {
    {
      "Berapakah hasil dari 37 + 12 = .....",
      "Berapakah hasil dari 81 - 49 = .....",
      "Berapakah hasil dari 160 + 32 - 50 = .....",
      "Berapakah hasil dari 74 + 55 - 17 = .....",
      "Berapakah hasil dari 759 - 64 + 55 - 19 = .....",
      "Berapakah hasil dari 2022 + 2045 - 1945 = .....",
      "Berapakah hasil dari 4321 - 1234 + 1010 = .....",
      "Berapakah hasil dari 5030 + 3079 + 2940 - 6432 = .....",
      "Berapakah hasil dari 3948 - 2108 = .....",
      "Berapakah hasil dari 1945 + 77",
    },
    {
      "Berapakah hasil dari 7 x 12 = .....",
      "Berapakah hasil dari (4 + 7) x 11 = .....",
      "Berapakah hasil dari 5 x 26 = .....",
      "Hitunglah :\n5 x 22 = .....",
      "Hitunglah :\n..... x 13 = 104\nNilai dari titik-titik diatas adalah .....",
      "Hitunglah :\n..... x 17 = 102\nNilai dari titik-titik diatas adalah .....",
      "Hitunglah :\n..... x 18 = 162\nNilai dari titik-titik diatas adalah .....",
      "Hitunglah :\n7 x ..... = 112\nNilai dari titik-titik diatas adalah .....",
      "Hitunglah :\n4 x ..... = 124\nNilai dari titik-titik diatas adalah .....",
      "Hitunglah :\n9 x ..... = 108\nNilai dari titik-titik diatas adalah .....",
    },
    {
      "Seseorang pedagang memiliki 750 buah jeruk, lalu laku terjual di pasar sebanyak 730\nkemudian pedang itu membeli jeruk lagi sebanyak 850 buah jeruk, setelah itu dimakan oleh anaknya 20 buah.\nJadi sekarang jumlah buah jeruk si pedang adalah ..... \n", //850
      "Oji memiliki 550 kelereng lalu dia bermain bersama Pila lalu kelah sebanyak 350 kelereng.\nKemudian dia membeli lagi kelereng sebanyak 250. Jadi jumlah kelereng milik Oji sekarang adalah .....\n", //450
      "Unang suka sekali membuat boneka dari sebuah kain flanel. Didalam satu hari, dia dapat membuat sampai 16 buah boneka. \nApabila dia secara terus menerus membuat boneka selama 15 hari berapakah boneka yang sudah di hasilkan Unang .....\n",//240
      "Pada suatu hari Rena berulang tahun. Dia ingin sekali merayakannya bersama dengan teman-teman yang sekelasnya. \nRencananya dia ingin mengundang teman sekelasnya yang berjumlah 25 anak. Selain itu juga, dia juga mengundang teman-temannya \nyang ada di sekitar rumah yang berjumlah 15 anak. Untuk itu semua, Rena menyiapkan sebuah bungkusan makanan ringan bagi teman-temannya itu. \nUntuk setiap bungkusnya, Rena mengisinya 8 macam dari makanan ringan. \nBerapakah jumlah keseluruhan makanan yang harus disiapkan oleh Rena supaya semua teman � temannya mendapat bagian yang rata .....?\n", //320
      "Pohon kelengkeng kakek berbuah begitu lebat. Di saat panen, kakek ingin sekali menjual kelengkengnya ke pasar. \nKemudian kakek membungkusnya menjadi 40 kantong. Untuk setiap kantongnya berisi 10 buah kelengkeng. \nJadi berapakah jumlah keseluruhan kelengkeng milik kakek yang akan dijualnya di pasar .....?\n",//400
      "Di suatu hari pak guru membawa 240 pensil warna ke sekolah agar diberikan pada murid-muridnya. \nApabila disetiap murid akan mendapatkan 5 pensil, jadi berapakah jumlah murid dari pak Guru .....?\n",//48
      "Pak Acong adalah seseorang pedagang buah jeruk. Didalam waktu 12 hari, dia sudah berhasil menjual 648 kg jeruk. \nJadi dalam sehari berapakah kilo yang terjual .....?\n",//54
      "Joni sangat gemar sekali membaca buku. untuk setiap hari, dia sudah membaca sebanyak 75 halaman buku. \nBerapakah jumlah halaman buku yang sudah dibaca Joni, apabila Jano itu membaca bukunya selama 28 hari, berapakah jumlah halaman buku tersebut .....\n",//2100
      "Dino sedang belajar untuk menggambar. Pada setiap hari dia akan menggambar lalu menghabiskan 8 lembar kertas putih. \nApabila Dino mempunyai 720 lembar kertas putih, maka untuk menghabiskan kertas putih tersebut membutuhkan berapa hari .....\n",//90
      "Ada sebuah kelompok anak pramuka yang jumlah anggotanya ada 35 anak, yang dimana setiap angotanya memiliki 5 buah topi. \nMaka jumlah keseluruhan topi milik anggota tersebut adalah .....\n", //175
    },
  };

  char *choices[3][10][4] = {
    {
      {"49", "50", "51", "52"},
      {"30", "31", "32", "33"},
      {"120", "142", "72", "132"},
      {"112", "115", "113", "114"},
      {"633", "621", "711", "731"},
      {"2985", "4029", "2122", "3478"},
      {"4087", "4097", "3877", "3947"},
      {"4617", "4517", "4377", "4567"},
      {"1940", "1860", "1970", "1840"},
      {"2021", "2022", "2023", "2024"}
    },
    {
      {"81", "82", "83", "84"},
      {"111", "121", "131", "141"},
      {"120", "130", "140", "150"},
      {"107", "108", "109", "110"},
      {"8", "9", "10", "11"},
      {"5", "6", "7", "8"},
      {"7", "8", "9", "10"},
      {"16", "17", "18", "19"},
      {"30", "31", "32", "33"},
      {"9", "10", "11", "12"},
    },
    {
      {"820", "830", "840", "850"}, 
      {"420", "430", "440", "450"},
      {"220", "230", "240", "250"},
      {"320", "330", "340", "350"},
      {"400", "410", "500", "510"},
      {"45", "46", "47", "48"},
      {"54", "55", "56", "57"},
      {"2100", "2200", "2300", "2400"},
      {"70", "80", "90", "100"},
      {"155", "165", "175", "185"},
    },
  };

  char keys[3][10] = {
    {'A', 'C', 'B', 'A', 'D', 'C', 'B', 'A', 'D', 'B'},
    {'D', 'B', 'B', 'D', 'A', 'B', 'C', 'A', 'B', 'D'},
    {'D', 'D', 'C', 'A', 'A', 'D', 'A', 'A', 'C', 'C'},
  };

  int level = 3;
 
  char name_admins[100][100] = {"Admin"};
  char username_admins[100][100] = {"admin"};
  char password_admins[100][100] = {"admin"};
  int len_admins = 1;
  char name_users[100][100] = {"User"};
  char username_users[100][100] = {"user"};
  char password_users[100][100] = {"user"};
  int scores[100][3] = {{0, 0, 0},};
  int time_playings[100][3] = {{0, 0, 0}};
  int len_users = 1;

  
  while(start(username_admins, name_admins, password_admins, &len_admins, username_users, name_users, password_users, &len_users, quests, choices, keys, scores, time_playings, level) == LOGOUT);
  
  return 0;
}
