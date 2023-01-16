# push_swap
https://user-images.githubusercontent.com/38822155/212700969-b2c7a97f-e325-4ea4-bf7c-fbfac4ef9421.mp4

## 概要
- 2つのスタック(a,b)、11種類のコマンドを利用してソートを行うプログラム
```
sa: スタック a の先頭の 2 要素を入れ替える。
sb: スタック b の先頭の 2 個の要素を入れ替える。
ss: sa と sb を同時に実行。
pa: bの先頭の要素を取ってaの先頭に置く。
pb: aの先頭の要素を取り出し、bの先頭に置く。
ra: スタック a の全要素を 1 ずつ上にシフトする。最初の要素が最後の要素になる。
rb: スタック b の全要素を 1 ずつ上に移動させる．最初の要素が最後の要素になる。
rr: ra と rb を同時に実行。
rra: スタック a の全要素を 1 つ下にシフトする。最後の要素が最初の要素になる。
rrb: スタック b のすべての要素を 1 つ下にシフトします。最後の要素が最初の要素になる．
rrr : rra と rrb を同時に実行。
```
## 使い方
```
make
./push_swap [数値]

Ex. ./push_swap 0 2 1 5 4 3
output: 
pb
pb
rrb
pa
ra
ra
pa
ra
pb
sa
ra
ra
pa
ra
```

## お借りしたビジュアライザ
https://github.com/o-reo/push_swap_visualizer
