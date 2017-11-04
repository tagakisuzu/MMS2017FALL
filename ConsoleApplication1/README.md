Dithering分法分析

* 原圖
![uncghanged](https://github.com/tagakisuzu/MMS2017FALL/blob/master/ConsoleApplication1/ConsoleApplication1/001.jpg)

* 灰階圖
使用𝑔𝑟𝑎𝑦(𝑥, 𝑦) = [𝑟𝑒𝑑(𝑥,𝑦)+𝑔𝑟𝑒𝑒𝑛(𝑥,𝑦)+𝑏𝑙𝑢𝑒(𝑥,𝑦)]/3的公式。 

* 使用Order 2x2完成的dithering
失真最為嚴重，因為矩陣較小，色塊分明，完成的圖片看起來成效頗差。
 
* 使用 4x4矩陣完成的dithering
狀況看起來較好，失真並沒有那個嚴重，色塊也不會那麼明顯了。
 
* 使用4x4矩陣完成的dithering (修改過該矩陣的版本)
出現了明顯的橫條紋，雖然失真並未有2x2的版本嚴重，但因為條紋的關係看起來成效也不怎麼樣。
 

以上是灰階圖、兩種演算法完成的dithering的比較，其中成效最好的就是使用4x4矩陣完成的dithering，當矩陣越大，色塊也越不明顯，失真程度降低，效果看起來也好多了，另外，修改矩陣，也會影響成像的效果。
