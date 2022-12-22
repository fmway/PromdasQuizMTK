# PromdasQuizMTK

# Flowchart
![flowchart](img/flowchart.jpg)

## Komponen
* [Struct Time](#struct-time)
* Fungsi :
  - [clear](#clear)
  - [gettimenow](#gettimenow)
  - [toseconds](#toseconds)
  - [getpasswd](#getpasswd)
  - [read\_line](#read_line)
  - [run\_questions](#run_questions)
  - [level\_questions](#level_questions)
  - [print\_questions](#print_questions)
  - [print\_choices](#print_choices)
  - [print\_keys](#print_keys)
  - [print\_score](#print_score)
  - [login](#login)
  - [reg](#reg)
  - [logout](#logout)
  - [start](#start)
  - [menu\_user](#menu_user)
  - [menu\_admin](#menu_admin)
  - [update\_questions](#update_questions)
  - [get\_quetions](#get_questions)
  - [get\_data](#get_data)

## Struct Time
  + Kode :
    ```c
    typedef struct Time {
      int hours;
      int minutes;
      int seconds;
    } Time;
    ```
  + Contoh Implementasi :
    ```c
    Time sekarang;
    sekarang.hours = 13;
    sekarang.minutes = 15;
    sekarang.seconds = 50;

    printf("Sekarang jam %d:%d:%d\n", sekarang.hours, sekarang.minutes, sekarang.seconds);
    ```

