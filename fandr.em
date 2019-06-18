
macro atest ()
{
	table = GetCurrentBuf ()
	tl = GetBufLnCur (table)
	lb = GetBufLine(table,tl)

	i=0
	j=strlen(lb)
	k = 0
	
	while(k!=6)
	{
		tmp = AsciiFromChar(lb[i])
		i++
		if (tmp != 34)
			continue

		k++
		if(k ==3)
			k3 = i
		if(k ==4)
			k4 = i-1
		if(k ==5)
			k5 = i
		if(k ==6)
			k6 = i-1
	}
	
	
	scn = strmid(lb,k3,k4)
	sen = strmid(lb,k5,k6)

	Msg(scn)
	Msg(sen

	/*
	sz = Ask("Enter string to search")

    hbuf = NewBuf("Results") // create output buffer
    if (hbuf == 0)
        stop
    SearchForRefs(hbuf, sz, 0)
    SetCurrentBuf(hbuf) // put buffer in a window
    totalLine = GetBufLineCount(hbuf)

    i = 0
    while (i<totalLine)
    {
		lr=GetSourceLink(hbuf,i)
		wfile=OpenBuf(lr.File)




		SaveBuf (lr.File)
		i++
    }

*/
}


macro InsertIfdef()
{
	sz = Ask("Enter ifdef condition:")
	if (sz != "")
		IfdefSz(sz);
}


// Wrap ifdef <sz> .. endif around the current selection
macro IfdefSz(sz)
{
	hwnd = GetCurrentWnd()
	lnFirst = GetWndSelLnFirst(hwnd)
	lnLast = GetWndSelLnLast(hwnd)
	 
	hbuf = GetCurrentBuf()
	InsBufLine(hbuf, lnFirst, "#ifdef @sz@")
	InsBufLine(hbuf, lnLast+2, "#endif /* @sz@ */")
}

