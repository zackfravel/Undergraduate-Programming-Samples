///////////////////////////////////
//  CSCE 3193			 //
//  Fall 2016			 //
//  Assignment 8		 //
//  Name: Zack Fravel		 //
///////////////////////////////////


/////////////////////////////
//       Recursion	   //
/////////////////////////////

function reverseArray(arr) 
{
	if(arr.length == 1) 
		return arr;

	return reverseArray(arr.slice(1)).concat(arr[0]);
}

function findMin(a) 
{
	if(a.length === 1)
		return a[0];
	else
		if(a[0] < a[1])
			return findMin(a.slice(2).concat(a[0]));
		else
			return findMin(a.slice(2).concat(a[1]));
}

function stringFromArrays(arr1, arr2) 
{
	if(arguments[2] == undefined)
	{
		arguments[2] = arr1.length;
		arguments[3] = 1;

	}else if(arguments[2] == 0){
		var stringArray = arr1.toString();
		return stringArray;
	}

	arr1.splice(arguments[3], 0, arr2.shift());
	arguments[3] += 2;
	arguments[2] -= 1;

	return stringFromArrays(arr1, arr2, arguments[2], arguments[3]);
}


//////////////////////////////////
//    Higher order functions	//
//////////////////////////////////

function applyToArray(a) 
{

	return function thing(foo)
	{

		if(a.length == 0)
			return a;

		var count;
		var holder;
	
		for(count = 0; count < a.length; count++)
		{
			holder = a.splice(count, 1);
			holder = foo(parseInt(holder));
			a.splice(count, 0, holder);
		}

		return a;

	}
		

}

function computeMaxArr(f1, f2)
{
	return function thing(a)
	{
		if(arguments[1] == undefined)
			arguments[1] = a.length;
		else if(arguments[1] == 0)
			return a;

		var holder;

		holder = a.splice(arguments[1] - 1, 1);
		holder = parseInt(holder);

		if(f1(holder) > f2(holder))
		{
			a.splice(arguments[1] - 1, 0, f1(holder));

		}else{
			a.splice(arguments[1] - 1, 0, f2(holder));

		}	

		return thing(a, arguments[1] - 1);		
	}

}


///////////////////////////
//    Common closure	 //
///////////////////////////

function makeClosure() 
{
	var counter = 0;
	var array = [];

	function foo1(a, b)
	{
		if(counter < 3)
			array.push(a + b);
		
		return array;
	}
	
	function foo2()
	{
		counter++;
	}

	var funcs = [foo1, foo2];

	return funcs;

}

//////////////////////////////////////////////
//  Auxiliary functions (used for testing)  //
//////////////////////////////////////////////

function mult4(i) { return i*4; }

function add2(j) { return j+2; }

function square(k) { return k*k; }
