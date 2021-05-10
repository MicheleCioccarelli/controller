<h1>Main Logic</h1>
This code can be uploaded on both a transmitter module (controller) and a receiver, this can be achieved by changing STATE's value between TX and RX.
The array which gets asd received is stuffToSend aka dataReceived and this is its structure:<br><br>

| Button | Lever | j_lX | j_lY | j_rX | j_lY | p_l | p_r | unused |<br>

<h3>Class documentation</h3>
<b>Common traits</b><br>
Every class has multiple constructors, most of them are for debugging as the unique values can be set using set() functions; everything interacts with stuffToSend[] using inject() methods, which place the object's values at the index, provided via the constructor.
<b>Button</b>
Every Button variable has 3 variables: id state value value: This is a compressed value and it carries the information of id and state, all in one variable.
Its decimal place number is the object's id, which can be 0~9 the controller only has 6 buttons. The number in the units place is the state, which can be either 0 or 1, depending on wether the button was pressed or not.<br>
This class is used for both buttons and switched (lever).
<b>Joystick</b>

Every joystick object occupies two places in stuffToSend[]: the on it is given via it's constructor and the one right after it. It holds Xvalue and Yvalue. It has 2 constructors: one for just pin number and index, where its unique variables are set to 0, and one where they can be provided.<br>
<b>Potentiometer</b>
A potentiometer onlhy needs one value, which needs to be processed as it gets input using map(), ths is because the component can register values between 0 and 1023, which is too large for uint8_t, map() cuts is down to a value between 0 and 255. 