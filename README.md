# arduino492

https://youtu.be/Vm5jSZbX5Rs

녹칸다의 ESPNOW와 BLYNK를 짬뽕시켜보는 예제이다!<BR>
크게 2가지 주제가 있다!<BR>
1. BLYNK에 센서데이터를 ESPNOW를 이용해서 전송한다!<BR>
2. BLYNK에 센서데이터를 업로드하되 저전력으로 시도한다(deepsleep)

1번은 BLYNK에 연결된 보드를 A라고하고 다른 하나의 보드를 B라고할때 B보드에 센서데이터가 있는 상황이다!<BR>
ESPNOW로 B에서 A로 전송해서 블링크 대시보드에 센서값을 출력하는 예시를 구현하면 된다!

그리고 반대로 BLYNK에서 제어명령을 A에서 B로 ESPNOW로 전송해서 제어하는 예시를 구현해보도록 해보자!

2번의 내용은 BLYNK에 연결된 보드A에 센서가 달려있다!<BR>
A보드는 집밖 어딘가에 베터리에 의존해서 작동하는 것으로 가정한다!<BR>
이때 최대한 베터리 소모량을 줄이면서 BLYNK쪽으로 센서값을 업로드 하는 방법에 대해서 예제를 만들어보도록 하자!<BR>
A보드가 부팅된다음 BLYNK클라우드와 접속하고 센서데이터를 업로드한다음 딥슬립(DeepSleep)을 작동시키는 개념이다!<BR>

잘작동 되는지 확인하고 딥슬립일때와 아닐때의 소모전류의 차이를 보이시오!

그리고 센서값이 업로드 될때의 시간을 BLYNK에 출력해보도록 하자!(블링크에 이미 그러한 기능이 내장되어 있었다)

(참고자료)
https://docs.blynk.io/en/


(실제로한거)

1.Blynk서버에 보드를 등록한다음 양방향으로 데이터를 주고받는 예제를 만드시오!

2.블링크와 연결되어있는 보드 A가 있고 A와 ESPNOW로 연결되는 보드B가 있을때 B보드에 있는 가상의 센서값을 블링크 서버로 업로드해서 출력하시오!

![492-2_bb](https://user-images.githubusercontent.com/106683637/171864210-482691fe-cf05-448b-af47-f82f072060a6.jpg)
  
3.(2)번기능에 더해서 블링크 클라우드에서 A보드에게 전송한 메시지를 A에서 B로 ESPNOW로 전달하는 예시를 구현하시오!

4.(2~3)번 예시에서 보드A가 블링크 서버와 완벽하게 연결된 다음 ESPNOW기능을 활성시키시오!(B보드 코드는 3과 동일함)

5.wemos d1 mini보드 1개를 blynk서버에 디바이스등록을하고 10초에한번마다 센서데이터를 업로드하고 나머지 시간에는 deepsleep하도록 하시오!(접속중일때70mA, 딥슬립을때 2.7mA)

![492-5_bb](https://user-images.githubusercontent.com/106683637/171864222-2e740016-a347-47d5-b83b-806dfabee441.jpg) 
  
6.(5)예제에서 센서데이터가 언제 업로드되었는지 시간값을 클라우드에 요청해서 업로드하시오!

7.blynk서버와 접속할때 timeout체크하는 시간이 너무 오래 걸려서 결론적으로 한사이클에 베터리낭비가 심한데 이것을 해결하시오!(setting.h에 timeout을 수정한다)

8.온습도센서(DHT-11)을 연결하고 센서값을 7번예제를 기본으로해서 클라우드로 업로드하시오!(저전력으로~)

![492-8_bb](https://user-images.githubusercontent.com/106683637/171864221-680a435b-2f66-4eac-aa73-376d01624e2e.jpg)
  
9.이산화탄소센서(MH-Z19)를 연결하고 센석밧을 클라우드로 업로드하시오!(저전력으로~)
이산화탄소센서는 S/W Serial로는 사용이 안되고 H/W Serial로 해야 가능하더라~
  
![492-9_bb](https://user-images.githubusercontent.com/106683637/171864215-9eb5b980-aff2-4e20-a5d8-f575f37658d3.jpg)
  
(Machine translation)<BR>
This is an example of mixing Nockanda's ESPNOW and BLYNK!<BR>
There are two main themes!<BR>
1. Transmit sensor data to BLYNK using ESPNOW!<BR>
2. Upload sensor data to BLYNK but try with low power (deepsleep)

In the first case, when the board connected to BLYNK is called A and the other board is called B, there is sensor data on board B!<BR>
Just implement an example of sending the sensor value from B to A with ESPNOW and outputting the sensor value on the blink dashboard!

And on the contrary, let's implement an example of controlling by sending a control command from A to B to ESPNOW in BLYNK!

As for the contents of number 2, the sensor is attached to board A connected to BLYNK!<BR>
A board is assumed to run on a battery somewhere outside the house!<BR>
At this time, let's make an example on how to upload sensor values ​​to BLYNK while reducing battery consumption as much as possible!<BR>
After the A board boots, it connects to the BLYNK cloud, uploads sensor data, and then operates DeepSleep!

Check if it works well and show the difference in current consumption during deep sleep and not!

And let's print the time when the sensor value is uploaded on BLYNK! (Blink already had such a function built-in)

(References)
https://docs.blynk.io/en/

(actually done)

1.Register the board on the Blynk server and make an example of exchanging data in both directions!

2.When there is board A connected to Blink and board B connected to A and ESPNOW, upload the virtual sensor value on board B to Blink server and print it out!

3.In addition to function (2), implement an example of passing the message sent from Blink Cloud to board A from A to B to ESPNOW!

4.In the example of (2~3), after board A is completely connected to the blink server, activate the ESPNOW function! (The code for board B is the same as 3)

5.Register one wemos d1 mini board to the blynk server, upload sensor data every 10 seconds, and deepsleep the rest of the time! (70mA when connected, 2.7mA when deep sleep)

6.(5)In the example, request the time value of when the sensor data was uploaded to the cloud and upload it!

7.When connecting to the blynk server, it takes too long to check the timeout, so as a result, the battery is wasted a lot in one cycle. Please fix this! (Modify the timeout in setting.h)

8.Connect the temperature and humidity sensor (DHT-11) and upload the sensor value to the cloud based on the 7th example! (with low power)

9.Connect the carbon dioxide sensor (MH-Z19) and upload Senseokbat to the cloud! (with low power)
Carbon dioxide sensor cannot be used with S/W Serial, but it is possible with H/W Serial~
