/* Include files */

#include "flightControlSystem_sfun.h"
#include "c4_flightControlSystem.h"
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtRSInfo c4_emlrtRSI = { 3,  /* lineNo */
  "Image Processing System/MATLAB Function2",/* fcnName */
  "#flightControlSystem:2347"          /* pathName */
};

static emlrtRSInfo c4_b_emlrtRSI = { 112,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c4_c_emlrtRSI = { 128,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c4_d_emlrtRSI = { 134,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c4_e_emlrtRSI = { 698,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c4_f_emlrtRSI = { 699,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c4_g_emlrtRSI = { 704,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c4_h_emlrtRSI = { 705,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c4_i_emlrtRSI = { 106,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c4_j_emlrtRSI = { 110,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c4_k_emlrtRSI = { 849,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c4_l_emlrtRSI = { 923,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c4_m_emlrtRSI = { 997,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c4_n_emlrtRSI = { 1025,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c4_o_emlrtRSI = { 1037,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c4_p_emlrtRSI = { 72,/* lineNo */
  "padarray",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\padarray.m"/* pathName */
};

static emlrtRSInfo c4_q_emlrtRSI = { 714,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c4_r_emlrtRSI = { 133,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c4_s_emlrtRSI = { 170,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c4_t_emlrtRSI = { 456,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c4_u_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\warning.m"/* pathName */
};

static emlrtRSInfo c4_v_emlrtRSI = { 757,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c4_w_emlrtRSI = { 751,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c4_x_emlrtRSI = { 859,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c4_y_emlrtRSI = { 76,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imreconstruct.m"/* pathName */
};

static emlrtRTEInfo c4_emlrtRTEI = { 729,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c4_b_emlrtRTEI = { 730,/* lineNo */
  37,                                  /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c4_c_emlrtRTEI = { 65,/* lineNo */
  9,                                   /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo c4_d_emlrtRTEI = { 730,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c4_e_emlrtRTEI = { 128,/* lineNo */
  6,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c4_f_emlrtRTEI = { 128,/* lineNo */
  17,                                  /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtBCInfo c4_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  137,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_b_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  138,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_c_emlrtBCI = { 1,/* iFirst */
  76,                                  /* iLast */
  100,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_d_emlrtBCI = { 1,/* iFirst */
  81,                                  /* iLast */
  100,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_e_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  756,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_f_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  751,                                 /* lineNo */
  70,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m",/* pName */
  0                                    /* checkKind */
};

static const real_T c4_dv[13] = { 3.4813359214923059E-5, 0.00054457256285105158,
  0.0051667606200595222, 0.029732654490475543, 0.10377716120747747,
  0.21969625200024598, 0.28209557151935094, 0.21969625200024598,
  0.10377716120747747, 0.029732654490475543, 0.0051667606200595222,
  0.00054457256285105158, 3.4813359214923059E-5 };

static const real_T c4_dv1[13] = { 0.0020299751839417137, 0.0102182810143517,
  0.058116735860084034, 0.19634433732941292, 0.37823877042972087,
  0.35505190018248872, 0.0, -0.35505190018248872, -0.37823877042972087,
  -0.19634433732941292, -0.058116735860084034, -0.0102182810143517,
  -0.0020299751839417137 };

static const real_T c4_dv2[12] = { 0.0020299751839417137, 0.0102182810143517,
  0.058116735860084034, 0.19634433732941292, 0.37823877042972087,
  0.35505190018248872, -0.35505190018248872, -0.37823877042972087,
  -0.19634433732941292, -0.058116735860084034, -0.0102182810143517,
  -0.0020299751839417137 };

static const boolean_T c4_bv[13] = { true, true, true, true, true, true, false,
  true, true, true, true, true, true };

/* Function Declarations */
static void initialize_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void enable_c4_flightControlSystem(SFc4_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void c4_update_jit_animation_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void c4_do_animation_call_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const mxArray *c4_st);
static void sf_gateway_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void initSimStructsc4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void c4_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_varargin_1[6156], real32_T c4_b[6156]);
static void c4_padImage(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_a_tmp[6156], real32_T c4_f_a[7128]);
static void c4_b_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_varargin_1[6156], real32_T c4_b[6156]);
static void c4_b_padImage(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_a_tmp[6156], real32_T c4_f_a[7068]);
static void c4_c_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_varargin_1[6156], real32_T c4_b[6156]);
static void c4_d_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_varargin_1[6156], real32_T c4_b[6156]);
static void c4_imhist(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, real32_T c4_varargin_1[6156],
                      real_T c4_yout[64]);
static void c4_warning(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp);
static void c4_thinAndThreshold(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, boolean_T c4_E[6156], real32_T c4_dx
  [6156], real32_T c4_dy[6156], real32_T c4_magGrad[6156], real_T
  c4_lowThresh_data[], int32_T c4_lowThresh_size[1], real_T c4_highThresh_data[],
  int32_T c4_highThresh_size[1], boolean_T c4_H[6156]);
static void c4_imreconstruct(SFc4_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c4_marker[6156], boolean_T c4_mask[6156], boolean_T
  c4_im[6156]);
static void c4_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_b_edgeBW, const char_T *c4_identifier,
  boolean_T c4_y[6156]);
static void c4_b_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  boolean_T c4_y[6156]);
static uint8_T c4_c_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_flightControlSystem, const
  char_T *c4_identifier);
static uint8_T c4_d_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static const mxArray *c4_chart_data_browse_helper
  (SFc4_flightControlSystemInstanceStruct *chartInstance, int32_T c4_ssIdNumber);
static const mxArray *c4_feval(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1);
static void c4_b_feval(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1);
static void init_dsm_address_info(SFc4_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc4_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c4_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c4_st.tls = chartInstance->c4_fEmlrtCtx;
  emlrtLicenseCheckR2012b(&c4_st, "image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_is_active_c4_flightControlSystem = 0U;
}

static void initialize_params_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_flightControlSystem(SFc4_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_jit_animation_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_do_animation_call_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static void ext_mode_exec_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(2, 1), false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", *chartInstance->c4_edgeBW, 11, 0U,
    1U, 0U, 2, 76, 81), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y",
    &chartInstance->c4_is_active_c4_flightControlSystem, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  int32_T c4_i;
  boolean_T c4_b_bv[6156];
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
                      "edgeBW", c4_b_bv);
  for (c4_i = 0; c4_i < 6156; c4_i++) {
    (*chartInstance->c4_edgeBW)[c4_i] = c4_b_bv[c4_i];
  }

  chartInstance->c4_is_active_c4_flightControlSystem = c4_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
     "is_active_c4_flightControlSystem");
  sf_mex_destroy(&c4_u);
  sf_mex_destroy(&c4_st);
}

static void sf_gateway_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c4_counts[64];
  real_T c4_b_data[1];
  real_T c4_b_highThresh_data[1];
  real_T c4_b_lowThresh_data[1];
  real_T c4_highThresh_data[1];
  real_T c4_lowThresh_data[1];
  real_T c4_b_idx;
  real_T c4_highThreshTemp;
  real_T c4_sum;
  int32_T c4_b_highThresh_size[1];
  int32_T c4_b_lowThresh_size[1];
  int32_T c4_highThresh_size[1];
  int32_T c4_lowThresh_size[1];
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_idx;
  int32_T c4_loop_ub;
  real32_T c4_b_dx[6156];
  real32_T c4_b_dy[6156];
  real32_T c4_dx[6156];
  real32_T c4_dy[6156];
  real32_T c4_f_a[6156];
  real32_T c4_h_a[6156];
  real32_T c4_b;
  real32_T c4_b_b;
  real32_T c4_b_r;
  real32_T c4_b_x;
  real32_T c4_b_x1;
  real32_T c4_b_x2;
  real32_T c4_b_y;
  real32_T c4_c_x;
  real32_T c4_c_y;
  real32_T c4_d_x;
  real32_T c4_d_y;
  real32_T c4_e_x;
  real32_T c4_e_y;
  real32_T c4_f_x;
  real32_T c4_f_y;
  real32_T c4_g_a;
  real32_T c4_g_x;
  real32_T c4_g_y;
  real32_T c4_h_x;
  real32_T c4_h_y;
  real32_T c4_i_a;
  real32_T c4_i_x;
  real32_T c4_i_y;
  real32_T c4_j_x;
  real32_T c4_j_y;
  real32_T c4_k_x;
  real32_T c4_k_y;
  real32_T c4_l_x;
  real32_T c4_l_y;
  real32_T c4_m_y;
  real32_T c4_magmax;
  real32_T c4_n_y;
  real32_T c4_r;
  real32_T c4_varargin_1;
  real32_T c4_varargin_2;
  real32_T c4_x;
  real32_T c4_x1;
  real32_T c4_x2;
  real32_T c4_y;
  int8_T c4_c_idx;
  boolean_T c4_b_bv[6156];
  boolean_T c4_bv1[6156];
  boolean_T c4_covSaturation;
  c4_st.tls = chartInstance->c4_fEmlrtCtx;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  chartInstance->c4_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c4_i = 0; c4_i < 6156; c4_i++) {
    covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 0U, (real_T)
                      (*chartInstance->c4_BW)[c4_i]);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c4_covrtInstance, 4U, 0, 0);
  c4_b_st.site = &c4_emlrtRSI;
  for (c4_i1 = 0; c4_i1 < 6156; c4_i1++) {
    chartInstance->c4_b_a[c4_i1] = (real32_T)(*chartInstance->c4_BW)[c4_i1];
  }

  c4_c_st.site = &c4_b_emlrtRSI;
  c4_d_st.site = &c4_e_emlrtRSI;
  for (c4_i2 = 0; c4_i2 < 6156; c4_i2++) {
    c4_f_a[c4_i2] = chartInstance->c4_b_a[c4_i2];
  }

  c4_imfilter(chartInstance, &c4_d_st, c4_f_a, c4_dx);
  c4_d_st.site = &c4_f_emlrtRSI;
  for (c4_i3 = 0; c4_i3 < 6156; c4_i3++) {
    c4_b_dx[c4_i3] = c4_dx[c4_i3];
  }

  c4_b_imfilter(chartInstance, &c4_d_st, c4_b_dx, c4_dx);
  c4_d_st.site = &c4_g_emlrtRSI;
  c4_c_imfilter(chartInstance, &c4_d_st, chartInstance->c4_b_a, c4_dy);
  c4_d_st.site = &c4_h_emlrtRSI;
  for (c4_i4 = 0; c4_i4 < 6156; c4_i4++) {
    c4_b_dy[c4_i4] = c4_dy[c4_i4];
  }

  c4_d_imfilter(chartInstance, &c4_d_st, c4_b_dy, c4_dy);
  c4_x = c4_dx[0];
  c4_y = c4_dy[0];
  c4_b_x = c4_x;
  c4_b_y = c4_y;
  c4_c_x = c4_b_x;
  c4_c_y = c4_b_y;
  c4_x1 = c4_c_x;
  c4_x2 = c4_c_y;
  c4_g_a = c4_x1;
  c4_b = c4_x2;
  c4_r = muSingleScalarHypot(c4_g_a, c4_b);
  chartInstance->c4_b_a[0] = c4_r;
  c4_magmax = chartInstance->c4_b_a[0];
  for (c4_idx = 0; c4_idx < 6155; c4_idx++) {
    c4_b_idx = (real_T)c4_idx + 2.0;
    c4_d_x = c4_dx[(int32_T)c4_b_idx - 1];
    c4_f_y = c4_dy[(int32_T)c4_b_idx - 1];
    c4_e_x = c4_d_x;
    c4_g_y = c4_f_y;
    c4_f_x = c4_e_x;
    c4_h_y = c4_g_y;
    c4_b_x1 = c4_f_x;
    c4_b_x2 = c4_h_y;
    c4_i_a = c4_b_x1;
    c4_b_b = c4_b_x2;
    c4_b_r = muSingleScalarHypot(c4_i_a, c4_b_b);
    chartInstance->c4_b_a[(int32_T)c4_b_idx - 1] = c4_b_r;
    c4_varargin_1 = chartInstance->c4_b_a[(int32_T)c4_b_idx - 1];
    c4_varargin_2 = c4_magmax;
    c4_g_x = c4_varargin_1;
    c4_i_y = c4_varargin_2;
    c4_h_x = c4_g_x;
    c4_j_y = c4_i_y;
    c4_i_x = c4_h_x;
    c4_k_y = c4_j_y;
    c4_j_x = c4_i_x;
    c4_l_y = c4_k_y;
    c4_k_x = c4_j_x;
    c4_m_y = c4_l_y;
    c4_l_x = c4_k_x;
    c4_n_y = c4_m_y;
    c4_magmax = muSingleScalarMax(c4_l_x, c4_n_y);
  }

  if (c4_magmax > 0.0F) {
    c4_d_y = c4_magmax;
    c4_e_y = c4_d_y;
    for (c4_i5 = 0; c4_i5 < 6156; c4_i5++) {
      chartInstance->c4_b_a[c4_i5] /= c4_e_y;
    }
  }

  c4_c_st.site = &c4_c_emlrtRSI;
  c4_d_st.site = &c4_q_emlrtRSI;
  for (c4_i6 = 0; c4_i6 < 6156; c4_i6++) {
    c4_h_a[c4_i6] = chartInstance->c4_b_a[c4_i6];
  }

  c4_imhist(chartInstance, &c4_d_st, c4_h_a, c4_counts);
  c4_sum = 0.0;
  c4_c_idx = 1;
  while ((!(c4_sum > 4309.2)) && ((real_T)c4_c_idx <= 64.0)) {
    c4_sum += c4_counts[c4_c_idx - 1];
    c4_i8 = c4_c_idx + 1;
    if (c4_i8 > 127) {
      c4_covSaturation = true;
      c4_i8 = 127;
      sf_data_saturate_error(chartInstance->S, 1U, 43, 16);
    } else {
      if (c4_i8 < -128) {
        c4_covSaturation = true;
        c4_i8 = -128;
        sf_data_saturate_error(chartInstance->S, 1U, 43, 16);
      }
    }

    covrtSaturationUpdateFcn(chartInstance->c4_covrtInstance, 4, 0, 0, 0,
      c4_covSaturation);
    c4_c_idx = (int8_T)c4_i8;
  }

  c4_i7 = c4_c_idx - 1;
  if (c4_i7 > 127) {
    c4_i7 = 127;
    sf_data_saturate_error(chartInstance->S, 1U, 43, 16);
  } else {
    if (c4_i7 < -128) {
      c4_i7 = -128;
      sf_data_saturate_error(chartInstance->S, 1U, 43, 16);
    }
  }

  c4_highThreshTemp = (real_T)(int8_T)c4_i7 / 64.0;
  if (((real_T)c4_c_idx > 64.0) && (!(c4_sum > 4309.2))) {
    c4_highThresh_size[0] = 0;
    c4_lowThresh_size[0] = 0;
  } else {
    c4_highThresh_size[0] = 1;
    c4_highThresh_data[0] = c4_highThreshTemp;
    c4_loop_ub = c4_highThresh_size[0] - 1;
    for (c4_i9 = 0; c4_i9 <= c4_loop_ub; c4_i9++) {
      c4_b_data[c4_i9] = c4_highThresh_data[c4_i9];
    }

    c4_b_data[0] *= 0.4;
    c4_lowThresh_size[0] = 1;
    c4_lowThresh_data[0] = c4_b_data[0];
  }

  for (c4_i10 = 0; c4_i10 < 6156; c4_i10++) {
    c4_b_bv[c4_i10] = false;
  }

  c4_b_lowThresh_size[0] = c4_lowThresh_size[0];
  c4_b_loop_ub = c4_lowThresh_size[0] - 1;
  for (c4_i11 = 0; c4_i11 <= c4_b_loop_ub; c4_i11++) {
    c4_b_lowThresh_data[c4_i11] = c4_lowThresh_data[c4_i11];
  }

  c4_b_highThresh_size[0] = c4_highThresh_size[0];
  c4_c_loop_ub = c4_highThresh_size[0] - 1;
  for (c4_i12 = 0; c4_i12 <= c4_c_loop_ub; c4_i12++) {
    c4_b_highThresh_data[c4_i12] = c4_highThresh_data[c4_i12];
  }

  c4_c_st.site = &c4_d_emlrtRSI;
  c4_thinAndThreshold(chartInstance, &c4_c_st, c4_b_bv, c4_dx, c4_dy,
                      chartInstance->c4_b_a, c4_b_lowThresh_data,
                      c4_b_lowThresh_size, c4_b_highThresh_data,
                      c4_b_highThresh_size, c4_bv1);
  for (c4_i13 = 0; c4_i13 < 6156; c4_i13++) {
    (*chartInstance->c4_edgeBW)[c4_i13] = c4_bv1[c4_i13];
  }

  c4_i14 = 1;
  emlrtDynamicBoundsCheckR2012b(c4_i14, 1, c4_lowThresh_size[0], &c4_emlrtBCI,
    &c4_b_st);
  c4_i15 = 1;
  emlrtDynamicBoundsCheckR2012b(c4_i15, 1, c4_highThresh_size[0], &c4_b_emlrtBCI,
    &c4_b_st);
  c4_do_animation_call_c4_flightControlSystem(chartInstance);
  for (c4_i16 = 0; c4_i16 < 6156; c4_i16++) {
    covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 1U, (real_T)
                      (*chartInstance->c4_edgeBW)[c4_i16]);
  }
}

static void mdl_start_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  static const uint32_T c4_decisionTxtEndIdx = 0U;
  static const uint32_T c4_decisionTxtStartIdx = 0U;
  setLegacyDebuggerFlag(chartInstance->S, false);
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c4_chart_data_browse_helper);
  chartInstance->c4_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c4_RuntimeVar,
    &chartInstance->c4_IsDebuggerActive,
    &chartInstance->c4_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c4_mlFcnLineNumber, &chartInstance->c4_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c4_covrtInstance, 1U, 0U, 1U,
    33U);
  covrtChartInitFcn(chartInstance->c4_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c4_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c4_decisionTxtStartIdx, &c4_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c4_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c4_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  1U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 87);
  covrtEmlSaturationInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 43, -1,
    59);
}

static void mdl_cleanup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c4_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c4_covrtInstance);
}

static void initSimStructsc4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

const mxArray *sf_c4_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static void c4_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_varargin_1[6156], real32_T c4_b[6156])
{
  emlrtStack c4_st;
  real_T c4_connDimsT[2];
  real_T c4_outSizeT[2];
  real_T c4_padSizeT[2];
  real_T c4_startT[2];
  int32_T c4_b_i;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  real32_T c4_b_varargin_1[6156];
  boolean_T c4_conn[13];
  boolean_T c4_b_modeFlag;
  boolean_T c4_c_modeFlag;
  boolean_T c4_modeFlag;
  boolean_T c4_tooBig;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_i_emlrtRSI;
  for (c4_i = 0; c4_i < 6156; c4_i++) {
    c4_b_varargin_1[c4_i] = c4_varargin_1[c4_i];
  }

  c4_padImage(chartInstance, &c4_st, c4_b_varargin_1, chartInstance->c4_a);
  c4_tooBig = true;
  for (c4_b_i = 0; c4_b_i < 2; c4_b_i++) {
    c4_tooBig = false;
  }

  if (!c4_tooBig) {
    c4_modeFlag = true;
  } else {
    c4_modeFlag = false;
  }

  if (c4_modeFlag) {
    c4_b_modeFlag = true;
  } else {
    c4_b_modeFlag = false;
  }

  c4_c_modeFlag = c4_b_modeFlag;
  if (c4_c_modeFlag) {
    for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
      c4_padSizeT[c4_i2] = 88.0 + -7.0 * (real_T)c4_i2;
    }

    for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
      c4_outSizeT[c4_i4] = 76.0 + 5.0 * (real_T)c4_i4;
    }

    for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
      c4_connDimsT[c4_i6] = 13.0 + -12.0 * (real_T)c4_i6;
    }

    ippfilter_real32(&chartInstance->c4_a[0], &c4_b[0], &c4_outSizeT[0], 2.0,
                     &c4_padSizeT[0], &c4_dv[0], &c4_connDimsT[0], true);
  } else {
    for (c4_i1 = 0; c4_i1 < 13; c4_i1++) {
      c4_conn[c4_i1] = true;
    }

    for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
      c4_padSizeT[c4_i3] = 88.0 + -7.0 * (real_T)c4_i3;
    }

    for (c4_i5 = 0; c4_i5 < 2; c4_i5++) {
      c4_outSizeT[c4_i5] = 76.0 + 5.0 * (real_T)c4_i5;
    }

    for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
      c4_connDimsT[c4_i7] = 13.0 + -12.0 * (real_T)c4_i7;
    }

    for (c4_i8 = 0; c4_i8 < 2; c4_i8++) {
      c4_startT[c4_i8] = 6.0 + -6.0 * (real_T)c4_i8;
    }

    imfilter_real32(&chartInstance->c4_a[0], &c4_b[0], 2.0, &c4_outSizeT[0], 2.0,
                    &c4_padSizeT[0], &c4_dv[0], 13.0, &c4_conn[0], 2.0,
                    &c4_connDimsT[0], &c4_startT[0], 2.0, true, true);
  }
}

static void c4_padImage(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_a_tmp[6156], real32_T c4_f_a[7128])
{
  static int32_T c4_idxA[176] = { 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
    29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66,
    67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 76, 76, 76, 76, 76, 76, 1, 2, 3, 4,
    5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
    25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43,
    44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62,
    63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81,
    0, 0, 0, 0, 0, 0, 0 };

  emlrtStack c4_st;
  real_T c4_b_i;
  real_T c4_b_j;
  int32_T c4_c_i;
  int32_T c4_i;
  int32_T c4_j;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_k_emlrtRSI;
  for (c4_j = 0; c4_j < 81; c4_j++) {
    c4_b_j = (real_T)c4_j + 1.0;
    for (c4_i = 0; c4_i < 88; c4_i++) {
      c4_b_i = (real_T)c4_i + 1.0;
      c4_c_i = c4_idxA[(int32_T)c4_b_j + 87];
      c4_f_a[((int32_T)c4_b_i + 88 * ((int32_T)c4_b_j - 1)) - 1] = c4_a_tmp
        [(emlrtDynamicBoundsCheckR2012b(c4_idxA[(int32_T)c4_b_i - 1], 1, 76,
           &c4_c_emlrtBCI, &c4_st) + 76 * (emlrtDynamicBoundsCheckR2012b(c4_c_i,
            1, 81, &c4_d_emlrtBCI, &c4_st) - 1)) - 1];
    }
  }
}

static void c4_b_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_varargin_1[6156], real32_T c4_b[6156])
{
  emlrtStack c4_st;
  real_T c4_connDimsT[2];
  real_T c4_outSizeT[2];
  real_T c4_padSizeT[2];
  real_T c4_startT[2];
  int32_T c4_b_i;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  real32_T c4_b_varargin_1[6156];
  boolean_T c4_b_modeFlag;
  boolean_T c4_c_modeFlag;
  boolean_T c4_modeFlag;
  boolean_T c4_tooBig;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_i_emlrtRSI;
  for (c4_i = 0; c4_i < 6156; c4_i++) {
    c4_b_varargin_1[c4_i] = c4_varargin_1[c4_i];
  }

  c4_b_padImage(chartInstance, &c4_st, c4_b_varargin_1, chartInstance->c4_e_a);
  c4_tooBig = true;
  for (c4_b_i = 0; c4_b_i < 2; c4_b_i++) {
    c4_tooBig = false;
  }

  if (!c4_tooBig) {
    c4_modeFlag = true;
  } else {
    c4_modeFlag = false;
  }

  if (c4_modeFlag) {
    c4_b_modeFlag = true;
  } else {
    c4_b_modeFlag = false;
  }

  c4_c_modeFlag = c4_b_modeFlag;
  if (c4_c_modeFlag) {
    for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
      c4_padSizeT[c4_i2] = 76.0 + 17.0 * (real_T)c4_i2;
    }

    for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
      c4_outSizeT[c4_i4] = 76.0 + 5.0 * (real_T)c4_i4;
    }

    for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
      c4_connDimsT[c4_i6] = 1.0 + 12.0 * (real_T)c4_i6;
    }

    ippfilter_real32(&chartInstance->c4_e_a[0], &c4_b[0], &c4_outSizeT[0], 2.0,
                     &c4_padSizeT[0], &c4_dv1[0], &c4_connDimsT[0], true);
  } else {
    for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
      c4_padSizeT[c4_i1] = 76.0 + 17.0 * (real_T)c4_i1;
    }

    for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
      c4_outSizeT[c4_i3] = 76.0 + 5.0 * (real_T)c4_i3;
    }

    for (c4_i5 = 0; c4_i5 < 2; c4_i5++) {
      c4_connDimsT[c4_i5] = 1.0 + 12.0 * (real_T)c4_i5;
    }

    for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
      c4_startT[c4_i7] = 6.0 * (real_T)c4_i7;
    }

    imfilter_real32(&chartInstance->c4_e_a[0], &c4_b[0], 2.0, &c4_outSizeT[0],
                    2.0, &c4_padSizeT[0], &c4_dv2[0], 12.0, &c4_bv[0], 2.0,
                    &c4_connDimsT[0], &c4_startT[0], 2.0, true, true);
  }
}

static void c4_b_padImage(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_a_tmp[6156], real32_T c4_f_a[7068])
{
  static int32_T c4_idxA[186] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
    34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52,
    53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71,
    72, 73, 74, 75, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
    1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
    19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
    38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56,
    57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75,
    76, 77, 78, 79, 80, 81, 81, 81, 81, 81, 81, 81 };

  emlrtStack c4_st;
  real_T c4_b_i;
  real_T c4_b_j;
  int32_T c4_c_i;
  int32_T c4_i;
  int32_T c4_j;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_k_emlrtRSI;
  for (c4_j = 0; c4_j < 93; c4_j++) {
    c4_b_j = (real_T)c4_j + 1.0;
    for (c4_i = 0; c4_i < 76; c4_i++) {
      c4_b_i = (real_T)c4_i + 1.0;
      c4_c_i = c4_idxA[(int32_T)c4_b_j + 92];
      c4_f_a[((int32_T)c4_b_i + 76 * ((int32_T)c4_b_j - 1)) - 1] = c4_a_tmp
        [(emlrtDynamicBoundsCheckR2012b(c4_idxA[(int32_T)c4_b_i - 1], 1, 76,
           &c4_c_emlrtBCI, &c4_st) + 76 * (emlrtDynamicBoundsCheckR2012b(c4_c_i,
            1, 81, &c4_d_emlrtBCI, &c4_st) - 1)) - 1];
    }
  }
}

static void c4_c_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_varargin_1[6156], real32_T c4_b[6156])
{
  emlrtStack c4_st;
  real_T c4_connDimsT[2];
  real_T c4_outSizeT[2];
  real_T c4_padSizeT[2];
  real_T c4_startT[2];
  int32_T c4_b_i;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  real32_T c4_b_varargin_1[6156];
  boolean_T c4_conn[13];
  boolean_T c4_b_modeFlag;
  boolean_T c4_c_modeFlag;
  boolean_T c4_modeFlag;
  boolean_T c4_tooBig;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_i_emlrtRSI;
  for (c4_i = 0; c4_i < 6156; c4_i++) {
    c4_b_varargin_1[c4_i] = c4_varargin_1[c4_i];
  }

  c4_b_padImage(chartInstance, &c4_st, c4_b_varargin_1, chartInstance->c4_d_a);
  c4_tooBig = true;
  for (c4_b_i = 0; c4_b_i < 2; c4_b_i++) {
    c4_tooBig = false;
  }

  if (!c4_tooBig) {
    c4_modeFlag = true;
  } else {
    c4_modeFlag = false;
  }

  if (c4_modeFlag) {
    c4_b_modeFlag = true;
  } else {
    c4_b_modeFlag = false;
  }

  c4_c_modeFlag = c4_b_modeFlag;
  if (c4_c_modeFlag) {
    for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
      c4_padSizeT[c4_i2] = 76.0 + 17.0 * (real_T)c4_i2;
    }

    for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
      c4_outSizeT[c4_i4] = 76.0 + 5.0 * (real_T)c4_i4;
    }

    for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
      c4_connDimsT[c4_i6] = 1.0 + 12.0 * (real_T)c4_i6;
    }

    ippfilter_real32(&chartInstance->c4_d_a[0], &c4_b[0], &c4_outSizeT[0], 2.0,
                     &c4_padSizeT[0], &c4_dv[0], &c4_connDimsT[0], true);
  } else {
    for (c4_i1 = 0; c4_i1 < 13; c4_i1++) {
      c4_conn[c4_i1] = true;
    }

    for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
      c4_padSizeT[c4_i3] = 76.0 + 17.0 * (real_T)c4_i3;
    }

    for (c4_i5 = 0; c4_i5 < 2; c4_i5++) {
      c4_outSizeT[c4_i5] = 76.0 + 5.0 * (real_T)c4_i5;
    }

    for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
      c4_connDimsT[c4_i7] = 1.0 + 12.0 * (real_T)c4_i7;
    }

    for (c4_i8 = 0; c4_i8 < 2; c4_i8++) {
      c4_startT[c4_i8] = 6.0 * (real_T)c4_i8;
    }

    imfilter_real32(&chartInstance->c4_d_a[0], &c4_b[0], 2.0, &c4_outSizeT[0],
                    2.0, &c4_padSizeT[0], &c4_dv[0], 13.0, &c4_conn[0], 2.0,
                    &c4_connDimsT[0], &c4_startT[0], 2.0, true, true);
  }
}

static void c4_d_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_varargin_1[6156], real32_T c4_b[6156])
{
  emlrtStack c4_st;
  real_T c4_connDimsT[2];
  real_T c4_outSizeT[2];
  real_T c4_padSizeT[2];
  real_T c4_startT[2];
  int32_T c4_b_i;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  real32_T c4_b_varargin_1[6156];
  boolean_T c4_b_modeFlag;
  boolean_T c4_c_modeFlag;
  boolean_T c4_modeFlag;
  boolean_T c4_tooBig;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_i_emlrtRSI;
  for (c4_i = 0; c4_i < 6156; c4_i++) {
    c4_b_varargin_1[c4_i] = c4_varargin_1[c4_i];
  }

  c4_padImage(chartInstance, &c4_st, c4_b_varargin_1, chartInstance->c4_c_a);
  c4_tooBig = true;
  for (c4_b_i = 0; c4_b_i < 2; c4_b_i++) {
    c4_tooBig = false;
  }

  if (!c4_tooBig) {
    c4_modeFlag = true;
  } else {
    c4_modeFlag = false;
  }

  if (c4_modeFlag) {
    c4_b_modeFlag = true;
  } else {
    c4_b_modeFlag = false;
  }

  c4_c_modeFlag = c4_b_modeFlag;
  if (c4_c_modeFlag) {
    for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
      c4_padSizeT[c4_i2] = 88.0 + -7.0 * (real_T)c4_i2;
    }

    for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
      c4_outSizeT[c4_i4] = 76.0 + 5.0 * (real_T)c4_i4;
    }

    for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
      c4_connDimsT[c4_i6] = 13.0 + -12.0 * (real_T)c4_i6;
    }

    ippfilter_real32(&chartInstance->c4_c_a[0], &c4_b[0], &c4_outSizeT[0], 2.0,
                     &c4_padSizeT[0], &c4_dv1[0], &c4_connDimsT[0], true);
  } else {
    for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
      c4_padSizeT[c4_i1] = 88.0 + -7.0 * (real_T)c4_i1;
    }

    for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
      c4_outSizeT[c4_i3] = 76.0 + 5.0 * (real_T)c4_i3;
    }

    for (c4_i5 = 0; c4_i5 < 2; c4_i5++) {
      c4_connDimsT[c4_i5] = 13.0 + -12.0 * (real_T)c4_i5;
    }

    for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
      c4_startT[c4_i7] = 6.0 + -6.0 * (real_T)c4_i7;
    }

    imfilter_real32(&chartInstance->c4_c_a[0], &c4_b[0], 2.0, &c4_outSizeT[0],
                    2.0, &c4_padSizeT[0], &c4_dv2[0], 12.0, &c4_bv[0], 2.0,
                    &c4_connDimsT[0], &c4_startT[0], 2.0, true, true);
  }
}

static void c4_imhist(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, real32_T c4_varargin_1[6156],
                      real_T c4_yout[64])
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  real_T c4_c_i;
  real_T c4_out;
  int32_T c4_b_c;
  int32_T c4_b_i;
  int32_T c4_c;
  int32_T c4_i;
  real32_T c4_b_x;
  real32_T c4_f_a;
  real32_T c4_g_a;
  real32_T c4_idx;
  real32_T c4_x;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_nanFlag;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_st.site = &c4_r_emlrtRSI;
  c4_b_st.site = &c4_s_emlrtRSI;
  c4_out = 1.0;
  getnumcores(&c4_out);
  for (c4_i = 0; c4_i < 64; c4_i++) {
    c4_yout[c4_i] = 0.0;
  }

  c4_nanFlag = false;
  for (c4_b_i = 0; c4_b_i < 6156; c4_b_i++) {
    c4_c_i = (real_T)c4_b_i + 1.0;
    c4_x = c4_varargin_1[(int32_T)c4_c_i - 1];
    c4_b = muSingleScalarIsNaN(c4_x);
    if (c4_b) {
      c4_nanFlag = true;
      c4_idx = 0.0F;
    } else {
      c4_idx = c4_varargin_1[(int32_T)c4_c_i - 1] * 63.0F + 0.5F;
    }

    if (c4_idx > 63.0F) {
      c4_yout[63]++;
    } else {
      c4_b_x = c4_varargin_1[(int32_T)c4_c_i - 1];
      c4_b_b = muSingleScalarIsInf(c4_b_x);
      if (c4_b_b) {
        c4_yout[63]++;
      } else {
        c4_f_a = c4_idx;
        c4_c = (int32_T)c4_f_a;
        c4_g_a = c4_idx;
        c4_b_c = (int32_T)c4_g_a;
        c4_yout[c4_c] = c4_yout[c4_b_c] + 1.0;
      }
    }
  }

  if (c4_nanFlag) {
    c4_b_st.site = &c4_t_emlrtRSI;
    c4_warning(chartInstance, &c4_b_st);
  }
}

static void c4_warning(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp)
{
  static char_T c4_msgID[27] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm',
    'h', 'i', 's', 't', 'c', ':', 'i', 'n', 'p', 'u', 't', 'H', 'a', 's', 'N',
    'a', 'N', 's' };

  static char_T c4_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c4_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 7), false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_msgID, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  c4_st.site = &c4_u_emlrtRSI;
  c4_b_feval(chartInstance, &c4_st, c4_y, c4_feval(chartInstance, &c4_st, c4_b_y,
              c4_c_y));
}

static void c4_thinAndThreshold(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, boolean_T c4_E[6156], real32_T c4_dx
  [6156], real32_T c4_dy[6156], real32_T c4_magGrad[6156], real_T
  c4_lowThresh_data[], int32_T c4_lowThresh_size[1], real_T c4_highThresh_data[],
  int32_T c4_highThresh_size[1], boolean_T c4_H[6156])
{
  real_T c4_szT[2];
  real_T c4_b_lowThresh;
  real_T c4_highThresh;
  real_T c4_lowThresh;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  boolean_T c4_b_E[6156];
  boolean_T c4_marker[6156];
  c4_i = 1;
  emlrtDynamicBoundsCheckR2012b(c4_i, 1, c4_lowThresh_size[0], &c4_f_emlrtBCI,
    c4_sp);
  c4_lowThresh = c4_lowThresh_data[0];
  c4_b_lowThresh = c4_lowThresh;
  for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
    c4_szT[c4_i1] = 76.0 + 5.0 * (real_T)c4_i1;
  }

  cannythresholding_real32_tbb(&c4_dx[0], &c4_dy[0], &c4_magGrad[0], &c4_szT[0],
    c4_b_lowThresh, &c4_E[0]);
  c4_i2 = 1;
  emlrtDynamicBoundsCheckR2012b(c4_i2, 1, c4_highThresh_size[0], &c4_e_emlrtBCI,
    c4_sp);
  c4_highThresh = c4_highThresh_data[0];
  for (c4_i3 = 0; c4_i3 < 6156; c4_i3++) {
    c4_marker[c4_i3] = ((real_T)c4_magGrad[c4_i3] > c4_highThresh);
  }

  for (c4_i4 = 0; c4_i4 < 6156; c4_i4++) {
    c4_b_E[c4_i4] = c4_E[c4_i4];
  }

  c4_imreconstruct(chartInstance, c4_marker, c4_b_E, c4_H);
}

static void c4_imreconstruct(SFc4_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c4_marker[6156], boolean_T c4_mask[6156], boolean_T
  c4_im[6156])
{
  real_T c4_imSizeT[2];
  int32_T c4_i;
  int32_T c4_i1;
  (void)chartInstance;
  for (c4_i = 0; c4_i < 6156; c4_i++) {
    c4_im[c4_i] = c4_marker[c4_i];
  }

  for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
    c4_imSizeT[c4_i1] = 76.0 + 5.0 * (real_T)c4_i1;
  }

  ippreconstruct_uint8((uint8_T *)&c4_im[0], (uint8_T *)&c4_mask[0],
                       &c4_imSizeT[0], 2.0);
}

static void c4_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_b_edgeBW, const char_T *c4_identifier,
  boolean_T c4_y[6156])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_edgeBW), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_edgeBW);
}

static void c4_b_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  boolean_T c4_y[6156])
{
  int32_T c4_i;
  boolean_T c4_b_bv[6156];
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_b_bv, 1, 11, 0U, 1, 0U, 2, 76,
                81);
  for (c4_i = 0; c4_i < 6156; c4_i++) {
    c4_y[c4_i] = c4_b_bv[c4_i];
  }

  sf_mex_destroy(&c4_u);
}

static uint8_T c4_c_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_flightControlSystem, const
  char_T *c4_identifier)
{
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_flightControlSystem), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_flightControlSystem);
  return c4_y;
}

static uint8_T c4_d_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_b_u;
  uint8_T c4_y;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_b_u, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_b_u;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static const mxArray *c4_chart_data_browse_helper
  (SFc4_flightControlSystemInstanceStruct *chartInstance, int32_T c4_ssIdNumber)
{
  const mxArray *c4_mxData = NULL;
  c4_mxData = NULL;
  switch (c4_ssIdNumber) {
   case 4U:
    sf_mex_assign(&c4_mxData, sf_mex_create("mxData", *chartInstance->c4_BW, 11,
      0U, 1U, 0U, 2, 76, 81), false);
    break;

   case 5U:
    sf_mex_assign(&c4_mxData, sf_mex_create("mxData", *chartInstance->c4_edgeBW,
      11, 0U, 1U, 0U, 2, 76, 81), false);
    break;
  }

  return c4_mxData;
}

static const mxArray *c4_feval(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1)
{
  const mxArray *c4_ = NULL;
  (void)chartInstance;
  c4_ = NULL;
  sf_mex_assign(&c4_, sf_mex_call(c4_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c4_input0), 14, sf_mex_dup(c4_input1)), false);
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
  return c4_;
}

static void c4_b_feval(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1)
{
  (void)chartInstance;
  sf_mex_call(c4_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c4_input0), 14,
              sf_mex_dup(c4_input1));
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
}

static void init_dsm_address_info(SFc4_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c4_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_BW = (boolean_T (*)[6156])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_edgeBW = (boolean_T (*)[6156])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c4_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1293160609U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3154668664U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3979909950U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1652456948U);
}

mxArray *sf_c4_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,5);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.IppfilterBuildable"));
  mxSetCell(mxcell3p, 1, mxCreateString(
             "images.internal.coder.buildable.ImfilterBuildable"));
  mxSetCell(mxcell3p, 2, mxCreateString(
             "images.internal.coder.buildable.GetnumcoresBuildable"));
  mxSetCell(mxcell3p, 3, mxCreateString(
             "images.internal.coder.buildable.CannyThresholdingTbbBuildable"));
  mxSetCell(mxcell3p, 4, mxCreateString(
             "images.internal.coder.buildable.IppreconstructBuildable"));
  return(mxcell3p);
}

mxArray *sf_c4_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("ippfilter_real32");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c4_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPhDBxMDABqQ4IEwwYIXyGaFijHBxFri4AhCXVBakgsSLi5I9U4B0XmIumJ9YWuG"
    "Zl5YPNt+CAWE+GxbzGZHM54SKQ8AHe8r0izig62fBop8NSb8AlJ+akp7qFA4NH2g4ke8OBQfK9E"
    "PsDyDgDwU0f4D4mcXxicklmWWp8ckm8Wk5mekZJc75eSVF+TnBlcUlqbkw/wEAhr0diA=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "skwA5Cl50ddnLgvmQ92UtNH";
}

static void sf_opaque_initialize_c4_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c4_flightControlSystem
    ((SFc4_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_flightControlSystem(void *chartInstanceVar)
{
  enable_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_flightControlSystem(void *chartInstanceVar)
{
  disable_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c4_flightControlSystem
    ((SFc4_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c4_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c4_flightControlSystem
      ((SFc4_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c4_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c4_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_flightControlSystem(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_flightControlSystem
      ((SFc4_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
    initSimStructsc4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c4_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [19] = {
    "eNrtV01v40QYdqNSsQKqgpBYEBIVF/ZYIVZiL9DGSbSR0m3B6e6xmo7f2KOMZ7zz4TT/hP/AhQM",
    "SnPgdXDly48AP4B3bTbOO7WwIWy2IkVx3PM/7zPs9E29neOrh2Mfnu/c8bw/fb+LT8YrxRjnfWX",
    "qK77veZ+X8RxQSNjkniiTaax2CJPAtaMmtYVIMxUTWwpiYgAJBEZtKZZrYNEssZ2I6sII6Pv0sZ",
    "jQOYml52EVZEp4JPke21Jpz5OkxBdQMAEITK2mjeMBJtNBYmZkfA51qm7SZoMEENnVq6VPLDUs5",
    "9K+BDoU2BDXWt7oFhhjwzXWjmc5SHdwAZZJyRkSttTHRAaToYAMXaYh/z6xBo6owGhNluhCTDPS",
    "ITXNOKaDKyTQuXDFBjFSM8H7CfSe4qts5R31OZQi8xSGoW1cBmaaSCdMc/2CAlvYFueLQgysbNb",
    "MF8Ny64D9lMAPV6LeJLzNQJIIz0bhp7pD+dR6tRZaswgxL4ClRJxTjpyFszF7MHB0QjBOMUaIJB",
    "rmRQz1WLEP3NrLZZOgyc13J2KQItl4Hy9n6GbRFYcE2oMInnOtG2FimI8iA56w9Ykg7rGCtx2nN",
    "wrFEB7v0bq4GKxgGvoT5UoSsNlxZBZD3nSfYWF5EUquNTHxM3t5otLq8ChsKA2pCKNR1AUWYBvR",
    "Z7t5mtpBpF3sEolYmV68OXGTIOpSnJ1b0ZlJN0SctTeTWBBfRRmCiI4wlVsKFxqJpg7lYrsNRQm",
    "MIXYNhHE6xbBBb4xPtWtsJ1l3GzLwHmiqW1kTVYtVhG+q7hJqncCGmQs7EQMkkKHt8EQXsDNjDE",
    "4zBOK8xQZGKaYPtgt1uHwJgUhIlmIi62ObUfIBK1kbMnXtH3u259/ZLnHs3ctX3gyWenRoeb+ld",
    "3fdep33fDv63U8odL8m9U9lntyLncAeuUn/7+cO3fnnwkfjp/qd/vvv979vs/0Nns3vCfjn/+KY",
    "hLwosW8lrh328pNduDf8HS/wH5VxPZycPff7wKAzFKMqSbx59fmGePC7is0bfTkXfm++H7mTAbM",
    "zzWNFhWF5g3JzY4lh3/F8u6bu3xh/3yu/F+OPr7eTfP67K1/lrr+IvN4cwgu6zF/P37+txeLydf",
    "LH/+Ro7Dit2HOb3gEviugtc0i8uJ5xFsTsYjJI8mGNbSPb/gXrbVM67Y7l/i57/++XV2/cy59dd",
    "y3l3LLetfZue468b/qilj3oV/MFrbMe296tXjf/V2+we9Ek5/2rxk8iPGQ9rbsflMt5hJ3Wr/5E",
    "83QT/F8inwSM=",
    ""
  };

  static char newstr [1289] = "";
  newstr[0] = '\0';
  for (i = 0; i < 19; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c4_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c4_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(431546734U));
  ssSetChecksum1(S,(438877707U));
  ssSetChecksum2(S,(572045166U));
  ssSetChecksum3(S,(3920302580U));
}

static void mdlRTW_c4_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c4_flightControlSystem(SimStruct *S)
{
  SFc4_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc4_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc4_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c4_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c4_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c4_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_flightControlSystem;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.chartStateSetterFcn = NULL;
  chartInstance->chartInfo.chartStateGetterFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c4_JITStateAnimation,
    chartInstance->c4_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c4_flightControlSystem(chartInstance);
}

void c4_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c4_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
