c++ 오목 게임
==========

 - 플레이어1, 플레이어2 를 정해서 서로 플레이가 가능합니다.
 - 컴퓨터와 플레이하는 싱글 모드도 가능합니다.
 - 시작하기 전에 오목 판의 크기 설정이 가능합니다. (예 : 19x19, 15x15 등)
 - 항상 흑부터 시작하며, 흑은 33 금지입니다. (백은 33 가능)


컴퓨터의 (x, y)위치 평가 방법
---------------------

1. 내가 돌을 놓았을 경우 5개 완성            ( 100 점 )
2. 상대방이 돌을 놓았을 경우에 5개 완성   ( 90 점 )
3. 내가 4개 (양 옆) 놓았을 경우               ( 80 점 )
4...
5......
이런 식으로 평가하여 컴퓨터가 돌을 놓게 됩니다.