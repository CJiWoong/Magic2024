var L_COLLAPSE_TEXT="모두 감추기";
var L_EXPAND_TEXT="모두 보이기";

function ExpandAll()
{
	// Expand all 
	var iSpan
	var iSpanSource
	var oSpan
	var sCaption
	var sAction
	var sImage
	
	// 액션 선택 및 그림 선택/변경
	sCaption=document.all("ExpandAll").innerHTML;
	if (sCaption==L_EXPAND_TEXT)
		{
		sAction="expanded";
		sImage="/images/icon_minus.gif"
		document.all("ExpandAll").innerHTML=L_COLLAPSE_TEXT;
		}
	else
		{
		sAction="collapsed";
		sImage="/images/icon_plus.gif"
		document.all("ExpandAll").innerHTML=L_EXPAND_TEXT;
		}

	// 모든 div를 열기	
	for (iSpan=0; iSpan < document.all.tags("DIV").length; iSpan++)
		{	
			oSpan=document.all.tags("DIV").item(iSpan);
			iSpanSource=oSpan.sourceIndex;
			if (oSpan.id=="expcol")
			{
				document.all.tags("DIV").item(iSpan).className=sAction;
				if(document.all(iSpanSource-1).tagName=="IMG" && document.all(iSpanSource-2).tagName!="IMG")
				{
					document.all(iSpanSource-1).src=sImage;
				}
				else if(document.all(iSpanSource-2).tagName=="IMG")
				{
					document.all(iSpanSource-2).src=sImage
				}
				 
			}			
			
		}


	// 텍스트 바꾸기
	document.all("ExpandAll").className="DropDown";

	// 팝업 처리
	var cLinks = document.all.tags("A");
	var iNumLinks = cLinks.length;

  	for (var i=0;i<iNumLinks;i++)
  	{
		cLink=document.all.tags("A").item(i);
		
		switch (sAction)
		{
			case 'expanded':
				if ((cLink.className=="glossary" || cLink.className=="Glossary") && cLink.getAttribute("State")!="On")
				{
					cLinks[i].click();
				}
				else if (cLink.className=="HidePopUp")
				{
					cLinks[i].click();
				}
				
				break;
			case 'collapsed':
				if ((cLink.className=="glossary" || cLink.className=="Glossary") && cLink.getAttribute("State")=="On")
				{
					cLinks[i].click();
				}
				else if (cLink.className=="HidePopUp")
				{
					cLinks[i].click();
				}
				break;
		}
  	}


	
	
}


function expdiv()
{

	window.event.returnValue=0	

	//DIV 태그 내용 보이기/감추기
	var open = event.srcElement;

	var el = checkParent(open,"A");
	if(null != el)
	{	
		var incr=0;
		var elmPos = 0;
		var parentSpan;
		var fBreak

		elemPos = window.event.srcElement.sourceIndex;

		//SPAN 태그 검색
		for (parentSpan = window.event.srcElement.parentElement;
			parentSpan!=null;
			parentSpan = parentSpan.parentElement) 
		{
		    if (parentSpan.tagName=="DIV") 
			{
				//alert("Parent Element is a SPAN");
				incr=1;
				break;
			}
			if (parentSpan.tagName=="BODY" || parentSpan.tagName=="UL" || parentSpan.tagName=="OL"|| parentSpan.tagName=="P") 
			{
				for (incr=1; (elemPos+incr) < document.all.length; incr++)
				{	
					if(document.all(elemPos+incr).tagName=="DIV" && 
					(document.all(elemPos+incr).className=="expanded" ||
					 document.all(elemPos+incr).className=="collapsed"))
					{
						fBreak=1;
						break;
					}
					else if(document.all(elemPos+incr).tagName=="LI")
					{
						return;
					}
				}
			}			
			if(fBreak==1)
			{
				break;
			}
		}

	}
	else
	{		
		return;
	}

	if(document.all(elemPos+incr).className=="collapsed")
	{
		
		document.all(elemPos+incr).className="expanded"
		document.all(elemPos+1).src="/images/icon_minus.gif";
		if(open.tagName=="IMG"){open.src="/images/icon_minus.gif";}
		if(open.tagName=="B")
			{
			if(open.parentElement.all.tags("IMG").length != 0)
				{open.parentElement.all.tags("IMG").item(0).src="/images/icon-obscure.gif";}
			}
	}
	else if(document.all(elemPos+incr).className=="expanded")
	{
		document.all(elemPos+incr).className="collapsed"
		document.all(elemPos+1).src="/images/icon_plus.gif";
		if(open.tagName=="IMG"){open.src="/images/icon_plus.gif";}
		if(open.tagName=="B")
			{
			if(open.parentElement.all.tags("IMG").length != 0)
				{open.parentElement.all.tags("IMG").item(0).src="/images/icon_plus.gif";}
			}
	}
	else
	{
		return;
	}
	event.cancelBubble = true;
//	open.scrollIntoView(true);
}


function checkParent(src,dest)
{
	//Search for a specific parent of the current element.
	while(src !=null)
	{
		if(src.tagName == dest)
		{
			return src;
		}
		src = src.parentElement;
	}
	return null;
}
