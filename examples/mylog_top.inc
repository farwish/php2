<h1 align=center>Summary of all hits</h1>
<center><form action="<?echo $PHP_SELF>" method=POST>
<input type="hidden" name="screen" value="mylog_top.inc">
<input type="hidden" name="PASSWORD" value="<?echo $PASSWORD>">
<input type="hidden" name="EMAIL_ADDR" value="<?echo $EMAIL_ADDR>">
Order listing by <select name=order>
<?if (!$order); $order="filename"; endif>
<option><?echo $order>
<?if($order!="filename")>
	<option>filename
<?endif>
<?if($order!="timestamp")>
	<option>timestamp
<?endif>
<?if($order!="total")>
	<option>total
<?endif>
<?if($order!="today")>
	<option>today
<?endif>
<?if($order!="host")>
	<option>host
<?endif>
<?if($order!="email")>
	<option>email
<?endif>
<?if($order!="lref")>
	<option>lref
<?endif>
<?if($order!="browser")>
	<option>browser
<?endif>
</select>
<input type="submit" value=" Redisplay ">
</form>
<form action="<?echo $PHP_SELF>" method=POST><table border=3>
<tr><th>Filename</th><th>Last Access</th><th>From</th><th>Total</th><th>Today</th></tr>
<?
	$uid = getmyuid();
	if($order=="filename");
		$result = mysql("phpfi","select * from last$uid order by $order");
	else;
		$myorder = $order;
		if($myorder == "timestamp");
			$myorder = "timestmp";
		endif;
		$result = mysql("phpfi","select * from last$uid order by $myorder desc");
	endif;
	$num = mysql_numrows($result);
	$i=0;
	while($i < $num);
		echo "<tr><td align=left>";
		$filename = mysql_result($result,$i,"filename");
		echo $filename;
		echo "</td><td align=center>";
		$last_time = mysql_result($result,$i,"timestmp");
		echo date("M d/y H:i:s",$last_time);
		echo "</td><td align=center>";
		echo mysql_result($result,$i,"host");
		echo "</td><td align=center>";
		echo mysql_result($result,$i,"total");
		echo "</td><td align=center>";
		if(date("z y",$last_time)==date("z y"));
			echo mysql_result($result,$i,"today");
		else;
			echo "0";
		endif>
		</td><td align=center><input type="radio" name="fn" value="<?echo $filename>" <?if($filename==$fn)>CHECKED<?endif>>
		<?echo "</td></tr>\n";
		$i++;
	endwhile;	
>
</table>
<select name="screen">
<option value="mylog_top.inc">Summary of hits on all pages
<option value="mylog_today.inc">Detailed Data for today's hits on a page
<option value="mylog_yesterday.inc">Detailed Data for yesterday's hits on a page
<option value="mylog_total.inc">Detailed Data for all hits on a page
<option value="mylog_ref.inc">Unique refering url's for a page
<input type="hidden" name="show_host" value="on">
<input type="hidden" name="PASSWORD" value="<?echo $PASSWORD>">
<input type="hidden" name="EMAIL_ADDR" value="<?echo $EMAIL_ADDR>">
</select><input type="submit" value=" View ">
</form></center>
