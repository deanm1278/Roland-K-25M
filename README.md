# Roland-K-25M
If you want to use a Roland K-25M for a custom synth

Roland's K-25M keyboard unit seems ideal for anyone who wants to make their own synth.
https://www.roland.com/us/products/k-25m/

Only issue is Roland has not released any schematics or info on how to integrate w/ custom units.

This project contains reverse engineered schematics for the unit (including pinout for the connector), as well as an example of how it can be used w/ Arduino. Note that usually you would want to use a keyboard controller IC (e.x. https://github.com/deanm1278/ADP5589_Arduino) instead of your main processor on the arduino for this, but I did not have one available today.

Pinout for the connector is:


And the key matrix (from left to right) is

<table>
<tr>
<td>0</td>
<td>1</td>
<td>2</td>
<td>3</td>
<td>4</td>
<td>5</td>
<td>6</td>
<td>7</td>
</tr>
<tr>
<td>8</td>
<td>9</td>
<td>10</td>
<td>11</td>
<td>12</td>
<td>13</td>
<td>14</td>
<td>15</td>
</tr>
<tr>
<td>16</td>
<td>17</td>
<td>18</td>
<td>29</td>
<td>20</td>
<td>21</td>
<td>22</td>
<td>23</td>
</tr>
<tr><td>24</td></tr>
</table>
