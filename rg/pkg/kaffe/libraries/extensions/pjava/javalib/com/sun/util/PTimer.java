/*
 * PTimer.java
 *
 * PersonalJava API 1.1
 *
 * Copyright (c) 1998
 *    Transvirtual Technologies, Inc.  All rights reserved.
 *
 * See the file "license.terms" for information on usage and redistribution 
 * of this file. 
 *
 */

package com.sun.util;

public abstract class PTimer {

public PTimer() {
}

public static PTimer getTimer() {
	return (PTimerImpl.getTimer());
}

public abstract void schedule(PTimerSpec t);
public abstract void deschedule(PTimerSpec t);

}
