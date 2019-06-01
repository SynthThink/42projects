
function create_cookie(name, content) {
	document.cookie= name + "=" + content + ";" + "expires=Thu, 18 Dec 2025 12:00:00 UTC;";
}

function ft_create_div(message)
{
	var parent_list = $('#ft_list');
	var new_div = $(document.createElement('div'));
	new_div.css({"height":'80px',"width":'200px',"border":'1px solid black',
	"marginTop":'10px', "marginBottom":'10px', "paddingLeft":'10px',
	"background":'black', "color":'white'});
	new_div.attr("class","div_test");
	new_div.text(message);
	parent_list.prepend(new_div);
	content.push(message);
	var json_content = JSON.stringify(content);
	create_cookie("divs", json_content);
}

function read_cookie(name)
{
	var text = document.cookie;
	var content_cookie = text.split(';');
	for(var i in content_cookie)
	{
		if (content_cookie[i].substring(0,4) == "divs")
		{
			var content = content_cookie[i].substring(5);
			content = JSON.parse(content);
			for(var c in content)
				ft_create_div(content[c]);
		}
	}
}

function ft_new (){
	var message = window.prompt();
	if (message != "" && message != null)
		ft_create_div(message);
}

function ft_delete (id){
	if (window.confirm("Do you really want to delete this note?"))
	{
		var search = id.firstChild;
		search = search['data'];
		var index = content.indexOf(search);
		if (index != -1)
		{
			content.splice(index, 1 );
			var json_content = JSON.stringify(content);
			create_cookie("divs", json_content);
		}
		id.parentNode.removeChild(id);
	}
}

var content = [];
read_cookie("divs");
$(document).ready(function() {
	$('#todo').click(function() {
		ft_new();
	});
	$(document).on("click", ".div_test", function(event) {
		ft_delete(event.target);
	});
});
