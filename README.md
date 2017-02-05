# Roland-K-25M
If you want to use a Roland K-25M for a custom synth

Roland's K-25M keyboard unit seems ideal for anyone who wants to make their own synth.
https://www.roland.com/us/products/k-25m/

Only issue is Roland has not released any schematics or info on how to integrate w/ custom units.

Fortuanately, the internals are very simple and contain no active circuitry. It is a charlieplexed matrix of switches w/ 2 switches per key. The velocity of the key press is proportional to the time in between contact for the two switches on each key.

This project contains everything you need use the K-25M for your own projects, including reverse engineered schematics for the unit, connector pinout, and an example of how it can be used w/ Arduino. Note that usually you would want to use a keyboard controller IC (e.x. https://github.com/deanm1278/ADP5589_Arduino) instead of your main processor on the arduino for this, but I did not have one available today.

Pinout for the connector is:

![screenshot 1](https://cloud.githubusercontent.com/assets/6306234/22630634/e611e726-ebcb-11e6-82a3-535f4228b4c1.png)

And the key matrix (from left to right) is

<table>
<tr>
<td>0</td>
<td>8</td>
<td>16</td>
<td>24</td>
</tr>
<tr>
<td>1</td>
<td>9</td>
<td>17</td>
<td></td>
</tr>
<tr>
<td>2</td>
<td>10</td>
<td>18</td>
<td></td>
</tr>
<tr>
<td>3</td>
<td>11</td>
<td>19</td>
<td></td>
</tr>
<tr>
<td>4</td>
<td>12</td>
<td>20</td>
<td></td>
</tr>
<tr>
<td>5</td>
<td>13</td>
<td>21</td>
<td></td>
</tr>
<tr>
<td>6</td>
<td>14</td>
<td>22</td>
<td></td>
</tr>
<tr>
<td>7</td>
<td>15</td>
<td>23</td>
<td></td>
</tr>

</table>
