
# SOURCE DATA
# DUC
# DDC
# Graph

object {
	obj_name=data_source
	exe_name=data_source
	outputs {
		name=output_0
		remote_itf=input_0
		remote_obj=GRAPH_DUC_IN
		#remote_obj=DUC17
	}
}


object {
	obj_name=GRAPH_DUC_IN
	exe_name=GRAPH
	force_pe=0
	inputs {
		name=input_0
		remote_itf=output_0
		remote_obj=data_source
	}
	outputs {
		name=output_0
		remote_itf=input_0
		remote_obj=DUCEFFICIENT
	}
}


object {
	obj_name=DUCEFFICIENT
	exe_name=DUCEFFICIENT
	force_pe=0
	inputs {
		name=input_0
		remote_itf=output_0
		remote_obj=data_source
	}
	outputs {
		name=output_0
		remote_itf=input_0
		remote_obj=GRAPH_DUC_OUT
	}
}

object {
	obj_name=GRAPH_DUC_OUT
	exe_name=GRAPH
	force_pe=0
	inputs {
		name=input_0
		remote_itf=output_0
		remote_obj=DUCEFFICIENT
	}
	outputs {
		name=output_0
		remote_itf=input_0
		remote_obj=DDCEFFICIENT
	}
}


object {
	obj_name=DDCEFFICIENT
	exe_name=DDCEFFICIENT
	force_pe=0
	inputs {
		name=input_0
		remote_itf=output_0
		remote_obj=GRAPH_DUC_OUT
	}
	outputs {
		name=output_0
		remote_itf=input_0
		remote_obj=GRAPH_DDC_OUT
	}
}

object {
	obj_name=GRAPH_DDC_OUT
	exe_name=GRAPH
	force_pe=0
	inputs {
		name=input_0
		remote_itf=output_0
		remote_obj=DDCEFFICIENT
	}
}
