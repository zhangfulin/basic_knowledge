从gwc表中查询firstprice=0的type,productid,newprice.同时拿查询出来的newprice更新gwc表中firstprice=0的firstprice

UPDATE gwc as r1,
(
  SELECT type,productid,newprice
  FROM   gwc
  WHERE  firstprice=0
) as r2
SET r1.firstprice = r2.newprice WHERE r1.type = r2.type AND r1.productid = r2.productid;
