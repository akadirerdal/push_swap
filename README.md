*This project has been created as part of the 42 curriculum by aberdal , sukonukc*

---

# 📌 push_swap

## 📖 Açıklama

`push_swap`, iki stack (`a` ve `b`) kullanarak bir sayı listesini **minimum operasyon sayısıyla sıralamayı** amaçlayan algoritmik bir projedir.

Bu projede amaç sadece sıralamak değil, **mümkün olan en az hamleyle sıralamaktır**. Bu nedenle algoritma seçimi ve optimizasyon kritik öneme sahiptir.

Program, verilen sayıları sıralamak için gerekli olan işlemleri standart output’a yazdırır.

Projeye göre maliyet, klasik zaman karmaşıklığı değil, **üretilen operasyon sayısıdır** .

---

# ⚙️ Kullanılabilir Operasyonlar

| Operasyon | Açıklama                  |
| --------- | ------------------------- |
| sa / sb   | İlk iki elemanı swap eder |
| ss        | sa + sb                   |
| pa / pb   | Stackler arası push       |
| ra / rb   | Yukarı döndür             |
| rr        | ra + rb                   |
| rra / rrb | Aşağı döndür              |
| rrr       | rra + rrb                 |

---

# 🎯 Amaç

* Algoritma karmaşıklığını öğrenmek
* Minimum operasyon üretmek
* Input’a göre doğru algoritmayı seçmek
* Edge-case ve hata kontrolü yapmak

---

# 🧠 Kullanılan Algoritmalar

Projede zorunlu olarak 4 farklı strateji implement edilmiştir :

---

## 🔹 1. Simple (O(n²))

Kullanım:

* Küçük inputlar
* Neredeyse sıralı diziler

Teknik:

* small sort (2–5 eleman)
* basit karşılaştırma tabanlı yaklaşım

---

## 🔹 2. Medium (O(n√n))

Teknik:

* chunk (parça) mantığı
* veri √n parçaya bölünür
* stack b’ye aktarılır ve geri toplanır

---

## 🔹 3. Complex (O(n log n))

Teknik:

* radix sort (bit tabanlı)
* indexleme kullanılır
* büyük inputlarda stabil ve hızlıdır

---

## 🔹 4. Adaptive (Dinamik Algoritma)

Bu algoritma input’a göre hangi yöntemin kullanılacağını belirler.

---

# 📊 Disorder (Bozukluk) Hesabı

Disorder, dizinin ne kadar sıralı olmadığını ölçer:

```text id="2q7xeh"
disorder = yanlış çift sayısı / toplam çift sayısı
```

* 0 → tamamen sıralı
* 1 → tamamen ters

Subject’te verilen mantık :

```c id="aq5t1c"
for i:
  for j:
    if a[i] > a[j]:
        mistakes++
```

---

# 📈 Adaptive Algoritma Mantığı

```c id="y02bxh"
if (size <= 5)
    small_sort();
else if (disorder < 0.2)
    simple_sort();
else if (disorder < 0.5)
    chunk_sort();
else
    radix_sort();
```

---

# 🧱 Proje Yapısı

```text id="mq8o7t"
src/
├── main.c
├── parsing.c
├── adaptive.c
├── sort_small.c
├── radix.c
├── chunk.c
├── operations/
│   ├── swap.c
│   ├── push.c
│   ├── rotate.c
│   └── reverse_rotate.c
├── bench.c
├── counter.c
├── index.c
```

---

# 🧩 Veri Yapıları

```c id="8q6klw"
typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *next;
} t_node;

typedef struct s_counter
{
    int sa, sb, ss;
    int pa, pb;
    int ra, rb, rr;
    int rra, rrb, rrr;
    int total;
} t_counter;
```

---

# 🚀 Kullanım

## Derleme

```bash id="d8l44g"
make
```

---

## Çalıştırma

```bash id="sztzpg"
./push_swap 3 2 1
```

---

## Algoritma seçimi

```bash id="4z5cde"
./push_swap --simple 3 2 1
./push_swap --medium 3 2 1
./push_swap --complex 3 2 1
./push_swap --adaptive 3 2 1
```

---

# 📊 Benchmark (Bench Mode)

```bash id="s7r2pm"
./push_swap --bench 3 2 1
```

Örnek çıktı:

```text id="skx67s"
[bench] disorder: 100.00%
[bench] strategy: Adaptive (O(n log n))
[bench] total_ops: 10
[bench] sa:1 sb:0 ss:0
[bench] pa:3 pb:3
[bench] ra:2 rb:0 rr:0
[bench] rra:1 rrb:0 rrr:0
```

---

# ⚠️ Hata Yönetimi

Program şu durumlarda `"Error\n"` yazdırır:

* integer olmayan input
* duplicate değerler
* int sınırını aşan değerler

---

# 📈 Performans Hedefleri

Subject’e göre :

| Eleman | Geçme  | İyi   | Mükemmel |
| ------ | ------ | ----- | -------- |
| 100    | <2000  | <1500 | <700     |
| 500    | <12000 | <8000 | <5500    |

---

# 🔍 Algoritma Seçim Mantığı

* Küçük input → özel optimize
* Orta → chunk
* Büyük → radix
* Adaptive → en uygun algoritmayı seçer

---

# 🤖 AI Kullanımı

AI şu amaçlarla kullanıldı:

* hata ayıklama
* algoritma tasarımı
* test üretimi
* kod organizasyonu

Tüm çıktılar manuel olarak kontrol edilmiştir.

---

# 📚 Kaynaklar

* 42 push_swap subject
* Big-O notasyonu
* Radix sort dokümantasyonu
* Sorting algoritmaları
