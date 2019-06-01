<?PHP
session_start();
if (isset($_SESSION['loggued_on_user']))
{
	$login = "";
	foreach($_SESSION['loggued_on_user'] as $key => $val)
	{
		$login = $key;
		break;
	}
		if ($_POST['msg'] != NULL)
		{
			$path = "../htdocs/private/chat";
			$user_data = array('login' => $login, 'time' => time(), 'msg' => $_POST['msg']);
			if (file_exists($path))
			{
				$fd = fopen($path, "rw");
				flock($fd, LOCK_EX);
				$file_data = unserialize(file_get_contents($path));
				$file_data[] = $user_data;
				file_put_contents($path, serialize($file_data));
				flock($fd, LOCK_UN);
				fclose($fd);
			}
			else
			{
				$file_data = array($user_data);
				file_put_contents($path, serialize($file_data));
			}
		}
}
else
{
	echo "ERROR\n";
	return ;
}
?>
<html>
<head>
	<script langage="javascript">top.frames['chat'].location='chat.php';</script>
</head>
<body>
<form action = "speak.php" method = "post">
	Message: <input name="msg" value="" />
</form>
</body></html>
