function ft_create_div(id, message)
{
	var parent_list = $('#ft_list');
	var new_div = $(document.createElement('div'));
	new_div.css({"height":'80px',"width":'200px',"border":'1px solid black',
	"marginTop":'10px', "marginBottom":'10px', "paddingLeft":'10px',
	"background":'black', "color":'white'});
	new_div.attr("class","div_test");
	new_div.attr("id",id);
	new_div.text(message);
	parent_list.prepend(new_div);
	content.push(message);
	$.ajax({
	    type: 'GET',
	    url: './insert.php',
	    data: { msg: message, name: id},
	});
}

function read_cookie(name)
{
	$.get('select.php', function(data, status) {
	var array = data.split("\n");
		for (var i = 0; i < array.length - 1; i++)
		{
			var tmp = array[i].split(';');
			ft_create_div(tmp[0], tmp[1]);
			id_count += 1;
		}
 	})
}

function ft_new (){
	var message = window.prompt();
	if (message != "" && message != null)
	{
		var id_add = String(id_count);
		id_add = "id".concat(id_add);
		ft_create_div(id_add, message);
		id_count += 1;
	}
}

function ft_delete (id_div){
	if (window.confirm("Do you really want to delete this note?"))
	{
		var search = id_div.firstChild;
		var id_delete = id_div.id;
		var text = $(id_div).text();
		$.ajax({
		    type: 'GET',
		    url: './delete.php',
		    data: { msg: text, name: id_delete},
		});
		id_div.parentNode.removeChild(id_div);
	}
}

var content = [];
var id_count = 0;
read_cookie("divs");
$(document).ready(function() {
	$('#todo').click(function() {
		ft_new();
	});
	$(document).on("click", ".div_test", function(event) {
		ft_delete(event.target);
	});
});
