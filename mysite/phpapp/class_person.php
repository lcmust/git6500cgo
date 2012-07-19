<?php
class Person {
	private $name;
	public $no_use1;
	function setName($name)
	{
		$this->name = $name;
	}

	function getName()
	{
		return $this->name;
	}
};

class HelloWorld {
	function display($count)
	{
		for ($i = 0; $i < $count; $i++) {
			print "Hello, World\n";
		}
		return $count;
	}
}

class HelloWorldDelegator {
	function __construct()
	{
		$this->obj = new HelloWorld();
	}

	function __call($method, $args)
	{
		return call_user_func_array(array($this->obj, $method), $args);
	}
	private $obj;
}
?>
