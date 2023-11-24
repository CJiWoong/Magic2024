(setq *magic_dir* (strcat (vl-registry-read "HKEY_CURRENT_USER\\Software\\Magic" "PATH") "\\Data\\"))

;;-------------------------------------------------------
;;                                                      -
;;    Form_Load                                         -
;;                                                      -
;;-------------------------------------------------------
(defun c:Gcad_Calc ()
  ;;------------------------------------------Layer List
  (setq cLname (getvar "clayer") k1 0)
  (setq nLname (cdr (assoc 2     (tblnext "layer" t)     )))
  (setq LayList (list nLname))
  (setq lname (tblnext "layer"))
  (while lname
    (setq lname (cdr (assoc 2 lname)))
    (if (/= (wcmatch lname "*|*") T) (setq LayList (cons lname LayList)) )
    (setq lname (tblnext "layer"))
  )
  (setq LayList (vl-sort LayList '<))
  (listtofile LayList (strcat *magic_dir* "Layer.out"))

  ;;------------------------------------------Style List
  (setq styleList '() sName (tblnext "style" 1))  
  (while sName
    (setq sss (strcase (cdr(assoc 2 sName))))
    (setq styleList (append styleList (list sss)))
    (setq sName (tblnext "style"))
  )
  (listtofile styleList (strcat *magic_dir* "Style.out"))

  (command "UI_CALC")
)

;;-------------------------------------------------------
;;                                                      -
;;    DataRead                                          -
;;                                                      -
;;-------------------------------------------------------
(defun DataRead ()
  (setq LastList (filetolist (strcat *magic_dir* "Last.out")))

  (setq CalMethod (nth 0 LastList))                   ;;---4/5=    ,  ׿ܴ      
  
  (setq AreaUnit (nth 12 LastList))                   ;;---        
  
  (setq Prec (atoi (nth 3 LastList)))                 ;;---   _ Ҽ    ڸ   .  
  (setq HatchColor "Yellow")                          ;;---Hatch    (    )
  (setq HatchUse (nth 13 LastList))                   ;;---Hatch    
  (setq HatchDel (nth 14 LastList))                   ;;---Hatch        
  (setq HatchPattern (nth 15 LastList))               ;;---Hatch Pattern
  (setq HatchScale (atoi (nth 16 LastList)))          ;;---Hatch Size

  (setq TextPrec (atoi (nth 17 LastList)))            ;;---TEXT  ڸ   
  (setq TextHeig (nth 2  LastList))                   ;;---TEXT     
  (setq Text1000 (nth 4 LastList))                    ;;---õ          (C / N)
  
  (setq tmpAlig (nth 5 LastList))                    ;;---        (TL/ML/BL...)
  (if (= tmpAlig "0")(setq TextAlig "TL"))
  (if (= tmpAlig "1")(setq TextAlig "ML"))
  (if (= tmpAlig "2")(setq TextAlig "BL"))  
  (if (= tmpAlig "3")(setq TextAlig "TC"))
  (if (= tmpAlig "4")(setq TextAlig "MC"))
  (if (= tmpAlig "5")(setq TextAlig "BC"))  
  (if (= tmpAlig "6")(setq TextAlig "TR"))
  (if (= tmpAlig "7")(setq TextAlig "MR"))
  (if (= tmpAlig "8")(setq TextAlig "BR"))  
  
  (setq TextAng  (nth 7 LastList))                    ;;---   ڰ   
  (setq ChgColor (nth 9 LastList))                    ;;---   ڻ  󺯰濩  (C/N)
  (setq TextColor (nth 8 LastList))                   ;;---   ڻ   (0/1/2...)
  (setq AddStr1  (nth 10 LastList))                   ;;--- Ӹ   
  (setq AddStr2  (nth 11 LastList))                   ;;---      
  (setq TextUnit (nth 12 LastList))                   ;;---      ȯ
  (setq TextSTYL (nth 18 LastList))                   ;;---    style
  (setq TextLay  (nth 19 LastList))                   ;;---    Layer
  (setq ScaleFac (* 0.001 (atoi (nth 20 LastList))))  ;;---SCALE FACTOR
)

;;-------------------------------------------------------
;;                                                      -
;;       ڻ                                             -
;;                                                      -
;;-------------------------------------------------------
(defun c:NewText ()
  (sysread)
  (DataRead)
  (setq tmp (getvar "users1"))
  (setq inputString (strcat AddStr1 tmp AddStr2))  
  (command "text" TextAlig (getpoint) TextHeig TextAng inputString)
  (setq e1 (entlast))
  (if (= ChgColor "C") (command "change" e1 "" "p" "c" TextColor ""))
  (command "change" e1 "" "p" "la" TextLay "")
    
  (setq tmpStyle (getvar "textstyle"))
  (if (/= tmpStyle TextSTYL)
    (progn
      (setq oldval (entget e1))
      (setq oldStyle (assoc 7 oldval))
      (setq newStyle (cons 7 TextSTYL))
      (setq newval (subst newStyle oldStyle oldval))
      (entmod newval)
    )
  )
  (sysreturn)
)

(defun c:ModText ()
  (sysread)
  (setq tmp (getvar "users1"))   
  
  (setq ss (ssget '((-4 . "<OR")(0 . "TEXT")(0 . "MTEXT")(-4 . "OR>"))))
  (if (/= ss nil)
    (progn
      (setq n1 0)  
      (repeat (sslength ss)	
        (setq oldEnt (ssname ss n1))    
        (setq oldVal (entget oldEnt))    
        (setq oldStr (assoc 1 oldVal))    
        (setq newStr (cons 1 tmp))    
        (setq newVal (subst newStr oldStr oldVal))    
        (entmod newVal)    
        (setq n1 (+ n1 1))
      )	
    )    
  )
  (sysreturn)
)

;;-------------------------------------------------------
;;                                                      -
;;     Ÿ                                              -
;;                                                      -
;;-------------------------------------------------------
(defun Dist_CalcResult ()
  (setq nn 0)
  (setq resValue 0)
  (setq resString (getvar "users1"))
  
  (repeat (length LengList)
    (setq tmp (nth nn LengList))
    (if (and (= nn 0) (= resString ""))
      (progn
	(setq resString tmp)
      )
      (progn
	(if (= (nth 1 LastList) "+") (setq resString (strcat resString "+" tmp)))
        (if (= (nth 1 LastList) "-") (setq resString (strcat resString "-" tmp)))
        (if (= (nth 1 LastList) "*") (setq resString (strcat resString "*" tmp)))
        (if (= (nth 1 LastList) "/") (setq resString (strcat resString "/" tmp)))
      )
    )  
    (setq nn (+ nn 1))
  )
  (if (= Text1000 "C")    
    (setq resValue (addComma (cal resString)))
    (setq resValue (rtos (cal resString) 2 Prec))
  )
  (setvar "Users2" resString)
  (setvar "Users3" resValue)
)

;;-------------------------------------------------------
;;                                                      -
;;                                                     -
;;                                                      -
;;-------------------------------------------------------
(defun Area_CalcResult ()
  (setq nn 0)
  (setq resValue 0)
  (setq resString (getvar "users1"))
  
  (repeat (length LengList)
    (setq tmp (nth nn LengList))
    (if (and (= nn 0) (= resString ""))
      (progn
	(setq resString tmp)
      )
      (progn
	(if (= (nth 1 LastList) "+") (setq resString (strcat resString "+" tmp)))
        (if (= (nth 1 LastList) "-") (setq resString (strcat resString "-" tmp)))
        (if (= (nth 1 LastList) "*") (setq resString (strcat resString "*" tmp)))
        (if (= (nth 1 LastList) "/") (setq resString (strcat resString "/" tmp)))
      )
    )  
    (setq nn (+ nn 1))
  )

  ;;----M2(PY) ƴѰ  .
  (if (or (= AreaUnit "0")(= AreaUnit "1")(= AreaUnit "2"))
    (progn
      (setq resValue1 (cal resString))
      ;(setq resValue2 (/ resValue1 3.3058))      
      (if (= Text1000 "C")	
	(setq resValue (addComma resValue1))
	(setq resValue (rtos resValue1 2 Prec))
      )
    )
  )
;;;  (if (= AreaUnit "2")
;;;    (progn
;;;      (setq resValue1 (cal resString))
;;;      ;(setq resValue2 (/ resValue1 3.3058))      
;;;      (if (= Text1000 "C")	
;;;	(setq resValue (addComma resValue1))
;;;	(setq resValue (rtos resValue2 2 Prec))
;;;      )      
;;;    )
;;;  )
  ;;----M2(PY)
  (if (= AreaUnit "3")
    (progn
      (setq resValue1 (cal resString))
      (setq resValue2 (/ resValue1 3.3058))      
      (if (= Text1000 "C")	
	(setq resValue (strcat (addComma resValue1) "  " "(" (addComma resValue2) "py" ")"))	  
	(setq resValue (strcat resValue1 "  " "(" resValue2 "py" ")"))	  
      )        
    )
  )
  
  (setvar "Users2" resString)
  (setvar "Users3" resValue)
)

(defun AddComma (aa / a b c d index)
  (setq a(fix aa))
  (if (not(zerop a))
    (progn 
      (setq b(rem aa a))
      (setq index 0)
      (foreach x (reverse(vl-string->list (itoa a)))
	(if (> index 2)
	  (setq c(cons x(cons 44 c)) index 1) 
	  (setq c(cons x c) index(1+ index))
	)
      )
      (setq d(apply 'strcat (mapcar 'chr c)))
      (if (> b 0)
	(strcat d(substr(rtos b)2))
	d 
      )
    )
    (rtos aa 2 Prec)
  )
)

;;-------------------------------------------------------
;;                                                      -
;;      ü                                             -
;;                                                      -
;;-------------------------------------------------------
(defun c:cleng1 ()
  (prompt "\n-----  ü        _1")
  (sysread)
  (DataRead)
  (setq ss (ssget '((-4 . "<OR")(0 . "LINE")(0 . "LWPOLYLINE")(0 . "POLYLINE")(0 . "ARC")(0 . "CIRCLE")(0 . "SPLINE")(0 . "ELLIPSE") (-4 . "OR>"))))
  (setq n1 0)
  
  (setq LengList '())
  (if (/= ss nil)
    (progn
      (repeat (sslength ss)
        (setq ent (ssname ss n1))
        (command "lengthen" ent "")
        ;(setq dist (RTOS (GETVAR "PERIMETER") 2 Prec))
	(setq dist (RTOS (* ScaleFac (GETVAR "PERIMETER")) 2 Prec))
        (princ (strcat "\n        : " dist))
        (setq LengList (append LengList (list dist)))    
        (setq n1 (+ n1 1))
	
      )
      (Dist_CalcResult)
    )
  )
  (sysreturn)
  (command "DispResult")
)

;;-------------------------------------------------------
;;                                                      -
;;     Ÿ                                              -
;;                                                      -
;;-------------------------------------------------------
(defun c:cleng2 ()
  (prompt "\n----- Ÿ     2")
  (DataRead)
  (sysread)
  (setq n1 0)  
  (setq LengList '())
  
  (while (setq p1 (getpoint "\nù  °           Ͻÿ ...:"))
    (setq p2 (getpoint p1"\n ι °           Ͻÿ ...:"))
    (setq dist (rtos (* ScaleFac (distance p1 p2)) 2 Prec))
    (princ (strcat "\n        : " dist))
    (setq LengList (append LengList (list dist)))    
    (setq p1 p2)
  )
  (Dist_CalcResult)
  
  (sysreturn)

  (command "DispResult")
)

;;-------------------------------------------------------
;;                                                      -
;;          Ÿ                                         -
;;                                                      -
;;-------------------------------------------------------
(defun c:cleng3 ()
  (prompt "\n-----    Ÿ     _3")
  (DataRead)
  (sysread)
  (setvar "orthomode" 1)
  (setq LengList '())  
  (while (setq p1 (getpoint "\nù  °           Ͻÿ ...:"))
    (setq p2 (getpoint p1"\n ι °           Ͻÿ ...:"))
    (setq p1x (nth 0 p1) p1y (nth 1 p1))
    (setq p2x (nth 0 p2) p2y (nth 1 p2))
    (setq dist (rtos (* ScaleFac (abs (- p1x p2x))) 2 Prec))
    (princ (strcat "\n        : " dist))
    (setq LengList (append LengList (list dist)))    
    (setq p1 p2)
  )
  (Dist_CalcResult)
  (sysreturn)
  (command "DispResult")
)

;;-------------------------------------------------------
;;                                                      -
;;          Ÿ                                         -
;;                                                      -
;;-------------------------------------------------------
(defun c:cleng4 ()
  (prompt "\n-----     Ÿ     _4")
  (DataRead)
  (sysread)
  (setvar "orthomode" 1)
  (setq LengList '())  
  (while (setq p1 (getpoint "\nù  °           Ͻÿ ...:"))
    (setq p2 (getpoint p1"\n ι °           Ͻÿ ...:"))
    (setq p1x (nth 0 p1) p1y (nth 1 p1))
    (setq p2x (nth 0 p2) p2y (nth 1 p2))
    (setq dist (rtos (* ScaleFac (abs (- p1y p2y))) 2 Prec))
    (princ (strcat "\n        : " dist))
    (setq LengList (append LengList (list dist)))    
    (setq p1 p2)
  )
  (Dist_CalcResult)
  (sysreturn)
  (command "DispResult")
)  

;;-------------------------------------------------------
;;                                                      -
;;                                                     -
;;                                                      -
;;-------------------------------------------------------
(defun c:cleng5 ()
  (prompt "\n-----        _5")
  (sysread)
  (DataRead)
  (setq ss (ssget '((-4 . "<OR")(0 . "TEXT")(0 . "MTEXT") (-4 . "OR>"))))
  (setq n1 0)
  
  (setq LengList '())
  (if (/= ss nil)
    (progn
      (repeat (sslength ss)
        (setq ent (ssname ss n1))
	
        (setq str (cdr (assoc 1 (entget ent))))

	;(alert str)
	
	(setq str_idd (substr str 1 4))
	(if (or (= str_idd "\\A0;")(= str_idd "\\A1;")(= str_idd "\\A2;")(= str_idd "\\C1;")(= str_idd "\\C2;")(= str_idd "\\C3;")(= str_idd "\\C4;")(= str_idd "\\C5;")(= str_idd "\\C6;")(= str_idd "\\C7;"))
	  (setq str (substr str 5))
	)  

	  ;(alert str)
	  
        (setq strList (DivideString str))    
        (setq n2 0)
        (setq noStr "")
        (repeat (length strList)
          (setq no (nth n2 strList))
          (if (and (>= (ascii no) 48) (<= (ascii no)  57)) (setq noStr (strcat noStr no)))
          (setq n2 (+ n2 1))
        )  

        (if (> (length (stringtolist noStr ".")) 2) (setq noStr "0"))   ;;----12.34.45          
        ;(setq dist noStr)
	(setq dist (rtos (atof noStr) 2 Prec))
        (princ (strcat "\n        : " dist))
        (setq LengList (append LengList (list dist)))    
        (setq n1 (+ n1 1))
      )
      (Dist_CalcResult)
    )
  )
  (sysreturn)
  (command "DispResult")
)

;;-------------------------------------------------------
;;                                                      -
;;    ġ                                               -
;;                                                      -
;;-------------------------------------------------------
(defun c:cleng6 ()
  (prompt "\n-----ġ      _6")
  (sysread)
  (DataRead)
  (setq ss (ssget '((0 . "DIMENSION"))))
  (setq n1 0)
  
  (setq LengList '())

  (if (/= ss nil)
    (progn
      (repeat (sslength ss)
        (setq ent (ssname ss n1))

	
        (setq orgDist (cdr (assoc 42 (entget ent))))
        (setq chgDist (cdr (assoc 1  (entget ent))))
        (if (/= chgDist "")
          (progn
  	    (if (= (vl-string-search "<>" chgDist) nil)
	      (progn
	        ;;---"R30.1234"
	        (setq strList (DivideString chgDist))
	         (setq n2 0)
                 (setq noStr "")
                 (repeat (length strList)
                   (setq no (nth n2 strList))
                   (if (and (>= (ascii no) 48) (<= (ascii no)  57)) (setq dist no))
                   (setq n2 (+ n2 1))
                 ) 
	      )
	      (progn
	        ;;---"R<>"
	        (setq dist (rtos orgDist 2 Prec))
	      )	  
	    )  
          )      
          (progn
	    (setq dist (rtos orgDist 2 Prec))
          )      
        )  
        (princ (strcat "\n        : " dist))
        (setq LengList (append LengList (list dist)))    
        (setq n1 (+ n1 1))
      )
      (if (/= LengList nil) (Dist_CalcResult))
    )
  )
  (sysreturn)
  (command "DispResult")
)

;;-------------------------------------------------------
;;                                                      -
;;             (           )                           -
;;                                                      -
;;-------------------------------------------------------
(defun c:carea1 ()
  (prompt "\n-----    _      ")
  (sysread)
  (DataRead)  
  (setvar "HPBOUND" 0)
  (setq ssHatch    (ssadd))
  (setq LengList '())
  (setq n1 0)      
  (while (setq p1 (getpoint "\n                              Ͻÿ ...:"))
    (command "boundary" p1 "") (setq Ent (entlast))
    (command "area" "" Ent)    
    ;;------------------------ Use Hatch
    (if (= HatchUse "HAT_USE")
      (progn
	(command "hatch" HatchPattern hatchscale 0 ent "")
	(setq Hent (entlast))
	(command "change" "l" "" "p" "c" HatchColor "")
	(ssadd Hent ssHatch)
      )
    )
    (entdel ent)
    ;;------------------------
    (setq tmp (* ScaleFac ScaleFac (GETVAR "area")))
    (if (= AreaUnit "0") (setq tmp tmp))                   ;;m2
    (if (= AreaUnit "1") (setq tmp (* tmp 0.001 0.001)))   ;;km2
    (if (= AreaUnit "2") (setq tmp (/ tmp 3.3058)))        ;;py
    (if (= AreaUnit "3") (setq tmp tmp))                   ;;m2(py)
    
    (setq curArea (RTOS tmp 2 Prec))	
    (princ (strcat "\n        : " CurArea))    
    (setq LengList (append LengList (list curArea)))	
    (setq n1 (+ n1 1))
  )
  (if (/= LengList nil) (Area_CalcResult))
  ;;------------------------ Use Delete
  (if (= HatchDel "HAT_DEL") (command "erase" ssHatch ""))
  (sysreturn)
  (command "DispResult")
)  

;;-------------------------------------------------------
;;                                                      -
;;             (    )                                  -
;;                                                      -
;;-------------------------------------------------------
(defun c:carea2 ()
  (prompt "\n-----    _    ")
  (sysread)
  (DataRead)  
  (setq ssHatch (ssadd))
  (setq LengList '())
  
  (while (setq ss (ssget '((-4 . "<OR")(0 . "LWPOLYLINE")(0 . "POLYLINE")(0 . "CIRCLE")(0 . "SPLINE")(0 . "ELLIPSE")(0 . "HATCH") (-4 . "OR>"))))  
    
    (if (/= ss nil)
      (progn
        (setq n1 0)      
        (repeat (sslength ss)	
          (setq ent (ssname ss n1))	
          (command "area" "" ent)
	  ;;------------------------ Use Hatch
	  (if (= HatchUse "HAT_USE")
	    (progn
	      (command "hatch" HatchPattern hatchscale 0 ent "")
	      (setq Hent (entlast))
	      (command "change" "l" "" "p" "c" HatchColor "")
	      (ssadd Hent ssHatch)
	    )
	  )  
	  ;;------------------------
	  (setq tmp (* ScaleFac ScaleFac (GETVAR "area")))
          (if (= AreaUnit "0") (setq tmp tmp))                   ;;m2
          (if (= AreaUnit "1") (setq tmp (* tmp 0.001 0.001)))   ;;km2
          (if (= AreaUnit "2") (setq tmp (/ tmp 3.3058)))        ;;py
          (if (= AreaUnit "3") (setq tmp tmp))                   ;;m2(py)
          (setq curArea (RTOS tmp 2 Prec))
          (princ (strcat "\n        : " CurArea))	
          (setq LengList (append LengList (list curArea)))	
          (setq n1 (+ n1 1))
        )
	(if (/= LengList nil) (Area_CalcResult))
      )
    )
  )
  ;;------------------------ Use Delete
  (if (= HatchDel "HAT_DEL") (command "erase" ssHatch ""))
  (sysreturn)
  (command "DispResult")
)  

;;-------------------------------------------------------
;;                                                      -
;;            ̾     OFF                                -
;;                                                      -
;;-------------------------------------------------------
;;;(defun C:LayerOFF ()
;;;  (setq adoc   (vla-get-activedocument (vlax-get-acad-object))
;;;        aclay  (vla-get-name (vla-get-activelayer adoc))
;;;        layers (vla-get-layers adoc)
;;;  )
;;;  (while (setq ent (entsel "\nSelect object on layer to OFF: "))
;;;    (setq obj (vlax-ename->vla-object (car ent))
;;;          lay (vla-get-layer obj)
;;;    )    
;;;    (if (/= (strcase lay) (strcase aclay))
;;;      (progn	
;;;	(vla-put-layeron (vla-item (vla-get-layers (vla-get-activedocument (vlax-get-acad-object ))) lay) :vlax-false)
;;;      )
;;;      (progn	
;;;	(vla-put-layeron (vla-item (vla-get-layers (vla-get-activedocument (vlax-get-acad-object ))) lay) :vlax-false)
;;;      )      
;;;    )
;;;  )
;;;  (princ)
;;;)

(defun c:LayerOFF ()
  (setq curLayer (getvar "clayer"))  
  (while
    (and (setq aaa (nentsel))
         (setq SelLayer (cdr (assoc 8 (entget (car aaa)))))
    )
    (if SelLayer
      (progn
        (princ (strcat "\n         ü      ̾   \"" SelLayer "\"  Դϴ ."))
        (if (= SelLayer curLayer)
          (command "layer" "off" SelLayer "y" "")
	  (command "layer" "off" SelLayer "")
        )	      
      )
      (progn
        (princ (strcat "\n         ü        ϴ ."))
      )  
    )
  )
  (princ)
)

;;-------------------------------------------------------
;;                                                      -
;;           ̾  On                                    -
;;                                                      -
;;-------------------------------------------------------
(defun c:layerOn ()  
  (command "layer" "on" "*" "")
  (princ)  
)

;;-------------------------------------------------------
;;                                                      -
;;            ̾     OFF                                -
;;                                                      -
;;-------------------------------------------------------
(defun c:layerSel ()  
  (setq e1 (nth 0 (entsel "\n  ü        Ͻÿ ...:")))
  (setq e2 (entget e1))
  (setq lname (cdr (assoc 8 e2)))
  (setvar "clayer" lname)
  (command "layer" "OFF" "*" "")
  (princ)  
)

;**************************
;      System Var read    *
;**************************
(defun sysRead ()
  (setvar "users4" "S")
  (setq osm     (getvar "osmode"))
  (setq lay     (getvar "clayer"))
  (setq lts     (getvar "ltscale"))
  (setq orh     (getvar "orthomode"))
)  
;**************************
;  System Var Return      *
;**************************
(defun sysReturn ()
  (setvar "users4" "E")
  (setvar "osmode"    osm)
  (setvar "clayer"    lay)
  (setvar "ltscale"   lts)
  (setvar "orthomode" orh)  
)

(defun myerror(S)
  (SysReturn)
  (setq *error* olderr)(princ)
  (setq olderr *error* *error* myerror)
  (alert "Program Canceled...!")
)

(defun FileToList(datfo)
  (setq out_lst '())
  (if (findfile datfo)
      (progn (setq out_lst '())
	     (setq datf(open datfo "r"))
	     (while (setq dali (read-line datf))
		    (setq dalj dali)
		    (setq out_lst (cons dalj out_lst))
	     );while
	     (close datf)
	     (setq out_lst (reverse out_lst))
      );progn
  );if
  out_lst
);defun

(defun StringToList (str_val str1 / n k val_lst sym_str val_s)
  (setq n 1 k t sym_str "" val_lst '())
  (if str_val (setq k t) (setq k nil))
  (while k
    (setq val_s (substr str_val n 1))
    (if (= val_s str1)
	(progn (setq val_lst (cons sym_str val_lst))
	       (setq sym_str "")
	);progn
	(setq sym_str (strcat sym_str val_s))
    );if
    (setq n (1+ n))
    (if (= val_s "") (setq k nil))
  );while
  (if val_lst
      (progn (setq val_lst (cons sym_str val_lst))
	     (setq val_lst(reverse val_lst))
      );progn
  );if
  (if (not val_lst)
      (setq val_lst (list str_val))
  )
  val_lst
);defun

(defun ListToFile(lst_val f_name)
  (setq out_file (open f_name "w"))
  (foreach val1 lst_val
    (cond ((= (type val1) 'INT)  (setq val1 (itoa val1)))
          ((= (type val1) 'REAL) (setq val1 (rtos val1)))
          ((= val1 nil) (setq val1 ""))
    )
    (if (/= (type val1) 'LIST)
        (write-line val1 out_file)
    )
  )
  (close out_file)
)

(defun ListToFileAppend(lst_val f_name)
  (setq out_file (open f_name "a"))
  (foreach val1 lst_val
    (cond ((= (type val1) 'INT)  (setq val1 (itoa val1)))
          ((= (type val1) 'REAL) (setq val1 (rtos val1)))
          ((= val1 nil) (setq val1 ""))
    )
    (if (/= (type val1) 'LIST)
        (write-line val1 out_file)
    )
  )
  (close out_file)
)

(defun dtr (a)  (* a (/ pi 180.0)))
(defun rtd (a)  (* a (/ 180.0 pi)))

(defun DivideString (a / n nn instr sp mnn  nnt)
    (setq n 1 nn "" instr "")
    (repeat (strlen a)
      (if (member (substr a n 1) '("-" "0" "1" "2" "3" "4" "5" "6" "7" "8" "9" "."))
        (setq nn (strcat nn (substr a n 1)) nnt nil )
        (setq instr (strcat instr (substr a n 1)) nnt t   )
      )
      (if (and (< 1 n ) (/= nnt mnn))
        (if nnt
          (setq sp (append sp (list nn))  nn "" )
          (setq sp (append sp (list instr))  instr "" )
        )
      )
      (setq n (1+ n))
      (if nnt   (setq mnn t)  (setq mnn nil))
    )
    (if (/= "" nn)
      (setq sp (append sp (list nn))  nn "" )
      (setq sp (append sp (list instr))  instr "" )
    )
    sp
)

(defun c:CmdCancel ()
  (alert "--")
  (while (< 0 (getvar 'cmdactive)) (command nil))

)  