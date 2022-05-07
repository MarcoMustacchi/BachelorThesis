/* Include files */

#include "flightControlSystem_sfun.h"
#include "c1_flightControlSystem.h"
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
static emlrtMCInfo c1_emlrtMCI = { 13, /* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtMCInfo c1_b_emlrtMCI = { 88,/* lineNo */
  9,                                   /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c1_c_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatefinite",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatefinite.m"/* pName */
};

static emlrtMCInfo c1_d_emlrtMCI = { 13,/* lineNo */
  37,                                  /* colNo */
  "validateinteger",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validateinteger.m"/* pName */
};

static emlrtMCInfo c1_e_emlrtMCI = { 395,/* lineNo */
  5,                                   /* colNo */
  "houghpeaks",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pName */
};

static emlrtMCInfo c1_f_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatepositive",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatepositive.m"/* pName */
};

static emlrtMCInfo c1_g_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validateodd",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validateodd.m"/* pName */
};

static emlrtMCInfo c1_h_emlrtMCI = { 415,/* lineNo */
  1,                                   /* colNo */
  "houghpeaks",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pName */
};

static emlrtMCInfo c1_i_emlrtMCI = { 18,/* lineNo */
  15,                                  /* colNo */
  "mean",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m"/* pName */
};

static emlrtRSInfo c1_emlrtRSI = { 3,  /* lineNo */
  "Image Processing System/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2340"          /* pathName */
};

static emlrtRSInfo c1_b_emlrtRSI = { 4,/* lineNo */
  "Image Processing System/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2340"          /* pathName */
};

static emlrtRSInfo c1_c_emlrtRSI = { 5,/* lineNo */
  "Image Processing System/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2340"          /* pathName */
};

static emlrtRSInfo c1_d_emlrtRSI = { 6,/* lineNo */
  "Image Processing System/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2340"          /* pathName */
};

static emlrtRSInfo c1_e_emlrtRSI = { 112,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_f_emlrtRSI = { 128,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_g_emlrtRSI = { 134,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_h_emlrtRSI = { 698,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_i_emlrtRSI = { 699,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_j_emlrtRSI = { 704,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_k_emlrtRSI = { 705,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_l_emlrtRSI = { 106,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c1_m_emlrtRSI = { 110,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c1_n_emlrtRSI = { 849,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c1_o_emlrtRSI = { 923,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c1_p_emlrtRSI = { 997,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c1_q_emlrtRSI = { 1025,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c1_r_emlrtRSI = { 1037,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c1_s_emlrtRSI = { 714,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_t_emlrtRSI = { 133,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c1_u_emlrtRSI = { 170,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c1_v_emlrtRSI = { 456,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c1_w_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\warning.m"/* pathName */
};

static emlrtRSInfo c1_x_emlrtRSI = { 757,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_y_emlrtRSI = { 751,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_ab_emlrtRSI = { 859,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c1_bb_emlrtRSI = { 76,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imreconstruct.m"/* pathName */
};

static emlrtRSInfo c1_cb_emlrtRSI = { 58,/* lineNo */
  "hough",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\hough.m"/* pathName */
};

static emlrtRSInfo c1_db_emlrtRSI = { 288,/* lineNo */
  "hough",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\hough.m"/* pathName */
};

static emlrtRSInfo c1_eb_emlrtRSI = { 61,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_fb_emlrtRSI = { 219,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_gb_emlrtRSI = { 265,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_hb_emlrtRSI = { 268,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_ib_emlrtRSI = { 76,/* lineNo */
  "validateattributes",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pathName */
};

static emlrtRSInfo c1_jb_emlrtRSI = { 383,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_kb_emlrtRSI = { 415,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_lb_emlrtRSI = { 404,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pathName */
};

static emlrtRTEInfo c1_emlrtRTEI = { 6,/* lineNo */
  17,                                  /* colNo */
  "Image Processing System/MATLAB Function1",/* fName */
  "#flightControlSystem:2340"          /* pName */
};

static emlrtRTEInfo c1_b_emlrtRTEI = { 729,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c1_c_emlrtRTEI = { 730,/* lineNo */
  37,                                  /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c1_d_emlrtRTEI = { 65,/* lineNo */
  9,                                   /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo c1_e_emlrtRTEI = { 730,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c1_f_emlrtRTEI = { 128,/* lineNo */
  6,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c1_g_emlrtRTEI = { 128,/* lineNo */
  17,                                  /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c1_h_emlrtRTEI = { 157,/* lineNo */
  38,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo c1_i_emlrtRTEI = { 147,/* lineNo */
  38,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo c1_j_emlrtRTEI = { 181,/* lineNo */
  5,                                   /* colNo */
  "houghpeaks",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pName */
};

static emlrtBCInfo c1_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  23,                                  /* colNo */
  "P",                                 /* aName */
  "Image Processing System/MATLAB Function1",/* fName */
  "#flightControlSystem:2340",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_b_emlrtBCI = { 1,/* iFirst */
  180,                                 /* iLast */
  6,                                   /* lineNo */
  19,                                  /* colNo */
  "T",                                 /* aName */
  "Image Processing System/MATLAB Function1",/* fName */
  "#flightControlSystem:2340",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_emlrtDCI = { 6,  /* lineNo */
  19,                                  /* colNo */
  "Image Processing System/MATLAB Function1",/* fName */
  "#flightControlSystem:2340",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_c_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  137,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_d_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  138,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_e_emlrtBCI = { 1,/* iFirst */
  60,                                  /* iLast */
  100,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_f_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  100,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_g_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  756,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_h_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  751,                                 /* lineNo */
  70,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_i_emlrtBCI = { 1,/* iFirst */
  341,                                 /* iLast */
  299,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "hough",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\hough.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_j_emlrtBCI = { 1,/* iFirst */
  60,                                  /* iLast */
  346,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "hough",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\hough.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_k_emlrtBCI = { 1,/* iFirst */
  341,                                 /* iLast */
  299,                                 /* lineNo */
  65,                                  /* colNo */
  "",                                  /* aName */
  "hough",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\hough.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_l_emlrtBCI = { 1,/* iFirst */
  61380,                               /* iLast */
  110,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "houghpeaks",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\houghpeaks.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_m_emlrtBCI = { 1,/* iFirst */
  341,                                 /* iLast */
  107,                                 /* lineNo */
  8,                                   /* colNo */
  "",                                  /* aName */
  "houghpeaks",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\houghpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_n_emlrtBCI = { 1,/* iFirst */
  180,                                 /* iLast */
  107,                                 /* lineNo */
  8,                                   /* colNo */
  "",                                  /* aName */
  "houghpeaks",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\houghpeaks.m",/* pName */
  0                                    /* checkKind */
};

static const real_T c1_dv[13] = { 3.4813359214923059E-5, 0.00054457256285105158,
  0.0051667606200595222, 0.029732654490475543, 0.10377716120747747,
  0.21969625200024598, 0.28209557151935094, 0.21969625200024598,
  0.10377716120747747, 0.029732654490475543, 0.0051667606200595222,
  0.00054457256285105158, 3.4813359214923059E-5 };

static const real_T c1_dv1[13] = { 0.0020299751839417137, 0.0102182810143517,
  0.058116735860084034, 0.19634433732941292, 0.37823877042972087,
  0.35505190018248872, 0.0, -0.35505190018248872, -0.37823877042972087,
  -0.19634433732941292, -0.058116735860084034, -0.0102182810143517,
  -0.0020299751839417137 };

static const real_T c1_dv2[12] = { 0.0020299751839417137, 0.0102182810143517,
  0.058116735860084034, 0.19634433732941292, 0.37823877042972087,
  0.35505190018248872, -0.35505190018248872, -0.37823877042972087,
  -0.19634433732941292, -0.058116735860084034, -0.0102182810143517,
  -0.0020299751839417137 };

static const boolean_T c1_bv[13] = { true, true, true, true, true, true, false,
  true, true, true, true, true, true };

/* Function Declarations */
static void initialize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void enable_c1_flightControlSystem(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_update_jit_animation_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_do_animation_call_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const mxArray *c1_st);
static void sf_gateway_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void initSimStructsc1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_edge(SFc1_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c1_sp, boolean_T c1_varargin_1[9600], boolean_T
                    c1_varargout_1[9600]);
static void c1_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_varargin_1[9600], real32_T c1_b[9600]);
static void c1_padImage(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_a_tmp[9600], real32_T c1_e_a[11520]);
static void c1_b_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_varargin_1[9600], real32_T c1_b[9600]);
static void c1_b_padImage(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_a_tmp[9600], real32_T c1_e_a[10320]);
static void c1_c_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_varargin_1[9600], real32_T c1_b[9600]);
static void c1_d_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_varargin_1[9600], real32_T c1_b[9600]);
static void c1_imhist(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, real32_T c1_varargin_1[9600],
                      real_T c1_yout[64]);
static void c1_warning(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp);
static void c1_thinAndThreshold(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, boolean_T c1_E[9600], real32_T
  c1_c_dx[9600], real32_T c1_b_dy[9600], real32_T c1_magGrad[9600], real_T
  c1_lowThresh_data[], int32_T c1_lowThresh_size[1], real_T c1_highThresh_data[],
  int32_T c1_highThresh_size[1], boolean_T c1_b_H[9600]);
static void c1_imreconstruct(SFc1_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c1_marker[9600], boolean_T c1_mask[9600], boolean_T
  c1_im[9600]);
static void c1_hough(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c1_sp, boolean_T c1_varargin_1[9600],
                     real_T c1_h[61380]);
static void c1_houghpeaks(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real_T c1_varargin_1[61380], real_T c1_peaks_data[],
  int32_T c1_peaks_size[2]);
static void c1_diff(SFc1_flightControlSystemInstanceStruct *chartInstance,
                    real_T c1_x[180], real_T c1_y[179]);
static void c1_b_diff(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      real_T c1_x[179], real_T c1_y[178]);
static real_T c1_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_Angle, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static uint8_T c1_c_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_flightControlSystem, const
  char_T *c1_identifier);
static uint8_T c1_d_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static const mxArray *c1_chart_data_browse_helper
  (SFc1_flightControlSystemInstanceStruct *chartInstance, int32_T c1_ssIdNumber);
static const mxArray *c1_feval(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, const mxArray *c1_input0, const
  mxArray *c1_input1);
static void c1_b_feval(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, const mxArray *c1_input0, const mxArray *c1_input1);
static void init_dsm_address_info(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c1_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c1_st.tls = chartInstance->c1_fEmlrtCtx;
  emlrtLicenseCheckR2012b(&c1_st, "image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_flightControlSystem = 0U;
}

static void initialize_params_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_flightControlSystem(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_jit_animation_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_do_animation_call_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static void ext_mode_exec_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(2, 1), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", chartInstance->c1_Angle, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y",
    &chartInstance->c1_is_active_c1_flightControlSystem, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  *chartInstance->c1_Angle = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 0)), "Angle");
  chartInstance->c1_is_active_c1_flightControlSystem = c1_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
     "is_active_c1_flightControlSystem");
  sf_mex_destroy(&c1_u);
  sf_mex_destroy(&c1_st);
}

static void sf_gateway_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  static char_T c1_cv[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack c1_b_st;
  emlrtStack c1_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c1_b_y = NULL;
  const mxArray *c1_y = NULL;
  real_T c1_DegAngle;
  real_T c1_b_Angle;
  real_T c1_c_y;
  real_T c1_d;
  int32_T c1_P_size[2];
  int32_T c1_x_size[2];
  int32_T c1_b_vlen;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_ix;
  int32_T c1_k;
  int32_T c1_loop_ub;
  int32_T c1_vlen;
  int32_T c1_xoffset;
  boolean_T c1_b_bv[9600];
  boolean_T c1_edgedBW[9600];
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_b2;
  c1_st.tls = chartInstance->c1_fEmlrtCtx;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  chartInstance->c1_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c1_i = 0; c1_i < 9600; c1_i++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 0U, (real_T)
                      (*chartInstance->c1_BW)[c1_i]);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c1_covrtInstance, 4U, 0, 0);
  c1_b_st.site = &c1_emlrtRSI;
  for (c1_i1 = 0; c1_i1 < 9600; c1_i1++) {
    c1_b_bv[c1_i1] = (*chartInstance->c1_BW)[c1_i1];
  }

  c1_edge(chartInstance, &c1_b_st, c1_b_bv, c1_edgedBW);
  c1_b_st.site = &c1_b_emlrtRSI;
  c1_hough(chartInstance, &c1_b_st, c1_edgedBW, chartInstance->c1_H);
  c1_b_st.site = &c1_c_emlrtRSI;
  c1_houghpeaks(chartInstance, &c1_b_st, chartInstance->c1_H,
                chartInstance->c1_P_data, c1_P_size);
  c1_b_st.site = &c1_d_emlrtRSI;
  c1_i2 = 2;
  c1_i3 = emlrtDynamicBoundsCheckR2012b(c1_i2, 1, c1_P_size[1], &c1_emlrtBCI,
    &c1_b_st) - 1;
  c1_i4 = c1_P_size[0];
  c1_x_size[1] = c1_i4;
  c1_loop_ub = c1_i4 - 1;
  for (c1_i5 = 0; c1_i5 <= c1_loop_ub; c1_i5++) {
    c1_d = chartInstance->c1_P_data[c1_i5 + c1_P_size[0] * c1_i3];
    c1_i6 = (int32_T)emlrtIntegerCheckR2012b(c1_d, &c1_emlrtDCI, &c1_b_st);
    chartInstance->c1_x_data[c1_i5] = -90.0 + (real_T)
      (emlrtDynamicBoundsCheckR2012b(c1_i6, 1, 180, &c1_b_emlrtBCI, &c1_b_st) -
       1);
  }

  c1_b = (c1_x_size[1] == 1);
  if (c1_b || ((real_T)c1_x_size[1] != 1.0)) {
    c1_b1 = true;
  } else {
    c1_b1 = false;
  }

  if (!c1_b1) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call(&c1_b_st, &c1_i_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14,
                sf_mex_call(&c1_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_b_st, NULL, "message", 1U, 1U, 14, c1_b_y)));
  }

  c1_vlen = c1_x_size[1];
  c1_b2 = (c1_x_size[1] == 0);
  if (c1_b2 || (c1_vlen == 0)) {
    c1_c_y = 0.0;
  } else {
    c1_b_vlen = c1_vlen;
    c1_c_y = chartInstance->c1_x_data[0];
    for (c1_k = 1; c1_k < c1_b_vlen; c1_k++) {
      c1_xoffset = c1_k + 1;
      c1_ix = c1_xoffset - 1;
      c1_c_y += chartInstance->c1_x_data[c1_ix];
    }
  }

  c1_DegAngle = c1_c_y / (real_T)c1_x_size[1];
  c1_b_Angle = c1_DegAngle;
  *chartInstance->c1_Angle = c1_b_Angle;
  c1_do_animation_call_c1_flightControlSystem(chartInstance);
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 1U,
                    *chartInstance->c1_Angle);
}

static void mdl_start_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  static const uint32_T c1_decisionTxtEndIdx = 0U;
  static const uint32_T c1_decisionTxtStartIdx = 0U;
  setLegacyDebuggerFlag(chartInstance->S, false);
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c1_chart_data_browse_helper);
  chartInstance->c1_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c1_RuntimeVar,
    &chartInstance->c1_IsDebuggerActive,
    &chartInstance->c1_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c1_mlFcnLineNumber, &chartInstance->c1_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c1_covrtInstance, 1U, 0U, 1U,
    22U);
  covrtChartInitFcn(chartInstance->c1_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c1_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c1_decisionTxtStartIdx, &c1_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 212);
}

static void mdl_cleanup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c1_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c1_covrtInstance);
}

static void initSimStructsc1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

const mxArray *sf_c1_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static void c1_edge(SFc1_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c1_sp, boolean_T c1_varargin_1[9600], boolean_T
                    c1_varargout_1[9600])
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  real_T c1_counts[64];
  real_T c1_b_data[1];
  real_T c1_b_highThresh_data[1];
  real_T c1_b_lowThresh_data[1];
  real_T c1_highThresh_data[1];
  real_T c1_lowThresh_data[1];
  real_T c1_b_idx;
  real_T c1_highThreshTemp;
  real_T c1_sum;
  int32_T c1_b_highThresh_size[1];
  int32_T c1_b_lowThresh_size[1];
  int32_T c1_highThresh_size[1];
  int32_T c1_lowThresh_size[1];
  int32_T c1_b_loop_ub;
  int32_T c1_c_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_idx;
  int32_T c1_loop_ub;
  real32_T c1_b_dy[9600];
  real32_T c1_f_a[9600];
  real32_T c1_b;
  real32_T c1_b_b;
  real32_T c1_b_r;
  real32_T c1_b_varargin_1;
  real32_T c1_b_x;
  real32_T c1_b_x1;
  real32_T c1_b_x2;
  real32_T c1_b_y;
  real32_T c1_c_x;
  real32_T c1_c_y;
  real32_T c1_d_x;
  real32_T c1_d_y;
  real32_T c1_e_a;
  real32_T c1_e_x;
  real32_T c1_e_y;
  real32_T c1_f_x;
  real32_T c1_f_y;
  real32_T c1_g_a;
  real32_T c1_g_x;
  real32_T c1_g_y;
  real32_T c1_h_x;
  real32_T c1_h_y;
  real32_T c1_i_x;
  real32_T c1_i_y;
  real32_T c1_j_x;
  real32_T c1_j_y;
  real32_T c1_k_x;
  real32_T c1_k_y;
  real32_T c1_l_x;
  real32_T c1_l_y;
  real32_T c1_m_y;
  real32_T c1_magmax;
  real32_T c1_n_y;
  real32_T c1_r;
  real32_T c1_varargin_2;
  real32_T c1_x;
  real32_T c1_x1;
  real32_T c1_x2;
  real32_T c1_y;
  int8_T c1_c_idx;
  boolean_T c1_b_bv[9600];
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  for (c1_i = 0; c1_i < 9600; c1_i++) {
    chartInstance->c1_b_a[c1_i] = (real32_T)c1_varargin_1[c1_i];
  }

  c1_st.site = &c1_e_emlrtRSI;
  c1_b_st.site = &c1_h_emlrtRSI;
  for (c1_i1 = 0; c1_i1 < 9600; c1_i1++) {
    chartInstance->c1_c_a[c1_i1] = chartInstance->c1_b_a[c1_i1];
  }

  c1_imfilter(chartInstance, &c1_b_st, chartInstance->c1_c_a,
              chartInstance->c1_dx);
  c1_b_st.site = &c1_i_emlrtRSI;
  for (c1_i2 = 0; c1_i2 < 9600; c1_i2++) {
    chartInstance->c1_b_dx[c1_i2] = chartInstance->c1_dx[c1_i2];
  }

  c1_b_imfilter(chartInstance, &c1_b_st, chartInstance->c1_b_dx,
                chartInstance->c1_dx);
  c1_b_st.site = &c1_j_emlrtRSI;
  c1_c_imfilter(chartInstance, &c1_b_st, chartInstance->c1_b_a,
                chartInstance->c1_dy);
  c1_b_st.site = &c1_k_emlrtRSI;
  for (c1_i3 = 0; c1_i3 < 9600; c1_i3++) {
    c1_b_dy[c1_i3] = chartInstance->c1_dy[c1_i3];
  }

  c1_d_imfilter(chartInstance, &c1_b_st, c1_b_dy, chartInstance->c1_dy);
  c1_x = chartInstance->c1_dx[0];
  c1_y = chartInstance->c1_dy[0];
  c1_b_x = c1_x;
  c1_b_y = c1_y;
  c1_c_x = c1_b_x;
  c1_c_y = c1_b_y;
  c1_x1 = c1_c_x;
  c1_x2 = c1_c_y;
  c1_e_a = c1_x1;
  c1_b = c1_x2;
  c1_r = muSingleScalarHypot(c1_e_a, c1_b);
  chartInstance->c1_b_a[0] = c1_r;
  c1_magmax = chartInstance->c1_b_a[0];
  for (c1_idx = 0; c1_idx < 9599; c1_idx++) {
    c1_b_idx = (real_T)c1_idx + 2.0;
    c1_d_x = chartInstance->c1_dx[(int32_T)c1_b_idx - 1];
    c1_f_y = chartInstance->c1_dy[(int32_T)c1_b_idx - 1];
    c1_e_x = c1_d_x;
    c1_g_y = c1_f_y;
    c1_f_x = c1_e_x;
    c1_h_y = c1_g_y;
    c1_b_x1 = c1_f_x;
    c1_b_x2 = c1_h_y;
    c1_g_a = c1_b_x1;
    c1_b_b = c1_b_x2;
    c1_b_r = muSingleScalarHypot(c1_g_a, c1_b_b);
    chartInstance->c1_b_a[(int32_T)c1_b_idx - 1] = c1_b_r;
    c1_b_varargin_1 = chartInstance->c1_b_a[(int32_T)c1_b_idx - 1];
    c1_varargin_2 = c1_magmax;
    c1_g_x = c1_b_varargin_1;
    c1_i_y = c1_varargin_2;
    c1_h_x = c1_g_x;
    c1_j_y = c1_i_y;
    c1_i_x = c1_h_x;
    c1_k_y = c1_j_y;
    c1_j_x = c1_i_x;
    c1_l_y = c1_k_y;
    c1_k_x = c1_j_x;
    c1_m_y = c1_l_y;
    c1_l_x = c1_k_x;
    c1_n_y = c1_m_y;
    c1_magmax = muSingleScalarMax(c1_l_x, c1_n_y);
  }

  if (c1_magmax > 0.0F) {
    c1_d_y = c1_magmax;
    c1_e_y = c1_d_y;
    for (c1_i4 = 0; c1_i4 < 9600; c1_i4++) {
      chartInstance->c1_b_a[c1_i4] /= c1_e_y;
    }
  }

  c1_st.site = &c1_f_emlrtRSI;
  c1_b_st.site = &c1_s_emlrtRSI;
  for (c1_i5 = 0; c1_i5 < 9600; c1_i5++) {
    c1_f_a[c1_i5] = chartInstance->c1_b_a[c1_i5];
  }

  c1_imhist(chartInstance, &c1_b_st, c1_f_a, c1_counts);
  c1_sum = 0.0;
  c1_c_idx = 1;
  while ((!(c1_sum > 6720.0)) && ((real_T)c1_c_idx <= 64.0)) {
    c1_sum += c1_counts[c1_c_idx - 1];
    c1_i7 = c1_c_idx + 1;
    if (c1_i7 > 127) {
      c1_i7 = 127;
      sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
    } else {
      if (c1_i7 < -128) {
        c1_i7 = -128;
        sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
      }
    }

    c1_c_idx = (int8_T)c1_i7;
  }

  c1_i6 = c1_c_idx - 1;
  if (c1_i6 > 127) {
    c1_i6 = 127;
    sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
  } else {
    if (c1_i6 < -128) {
      c1_i6 = -128;
      sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
    }
  }

  c1_highThreshTemp = (real_T)(int8_T)c1_i6 / 64.0;
  if (((real_T)c1_c_idx > 64.0) && (!(c1_sum > 6720.0))) {
    c1_highThresh_size[0] = 0;
    c1_lowThresh_size[0] = 0;
  } else {
    c1_highThresh_size[0] = 1;
    c1_highThresh_data[0] = c1_highThreshTemp;
    c1_loop_ub = c1_highThresh_size[0] - 1;
    for (c1_i8 = 0; c1_i8 <= c1_loop_ub; c1_i8++) {
      c1_b_data[c1_i8] = c1_highThresh_data[c1_i8];
    }

    c1_b_data[0] *= 0.4;
    c1_lowThresh_size[0] = 1;
    c1_lowThresh_data[0] = c1_b_data[0];
  }

  for (c1_i9 = 0; c1_i9 < 9600; c1_i9++) {
    c1_b_bv[c1_i9] = false;
  }

  c1_b_lowThresh_size[0] = c1_lowThresh_size[0];
  c1_b_loop_ub = c1_lowThresh_size[0] - 1;
  for (c1_i10 = 0; c1_i10 <= c1_b_loop_ub; c1_i10++) {
    c1_b_lowThresh_data[c1_i10] = c1_lowThresh_data[c1_i10];
  }

  c1_b_highThresh_size[0] = c1_highThresh_size[0];
  c1_c_loop_ub = c1_highThresh_size[0] - 1;
  for (c1_i11 = 0; c1_i11 <= c1_c_loop_ub; c1_i11++) {
    c1_b_highThresh_data[c1_i11] = c1_highThresh_data[c1_i11];
  }

  c1_st.site = &c1_g_emlrtRSI;
  c1_thinAndThreshold(chartInstance, &c1_st, c1_b_bv, chartInstance->c1_dx,
                      chartInstance->c1_dy, chartInstance->c1_b_a,
                      c1_b_lowThresh_data, c1_b_lowThresh_size,
                      c1_b_highThresh_data, c1_b_highThresh_size, c1_varargout_1);
  c1_i12 = 1;
  emlrtDynamicBoundsCheckR2012b(c1_i12, 1, c1_lowThresh_size[0], &c1_c_emlrtBCI,
    c1_sp);
  c1_i13 = 1;
  emlrtDynamicBoundsCheckR2012b(c1_i13, 1, c1_highThresh_size[0], &c1_d_emlrtBCI,
    c1_sp);
}

static void c1_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_varargin_1[9600], real32_T c1_b[9600])
{
  emlrtStack c1_st;
  real_T c1_connDimsT[2];
  real_T c1_outSizeT[2];
  real_T c1_padSizeT[2];
  real_T c1_startT[2];
  int32_T c1_b_i;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  real32_T c1_b_varargin_1[9600];
  boolean_T c1_conn[13];
  boolean_T c1_b_modeFlag;
  boolean_T c1_c_modeFlag;
  boolean_T c1_modeFlag;
  boolean_T c1_tooBig;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_l_emlrtRSI;
  for (c1_i = 0; c1_i < 9600; c1_i++) {
    c1_b_varargin_1[c1_i] = c1_varargin_1[c1_i];
  }

  c1_padImage(chartInstance, &c1_st, c1_b_varargin_1, chartInstance->c1_a);
  c1_tooBig = true;
  for (c1_b_i = 0; c1_b_i < 2; c1_b_i++) {
    c1_tooBig = false;
  }

  if (!c1_tooBig) {
    c1_modeFlag = true;
  } else {
    c1_modeFlag = false;
  }

  if (c1_modeFlag) {
    c1_b_modeFlag = true;
  } else {
    c1_b_modeFlag = false;
  }

  c1_c_modeFlag = c1_b_modeFlag;
  if (c1_c_modeFlag) {
    for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
      c1_padSizeT[c1_i2] = 72.0 + 88.0 * (real_T)c1_i2;
    }

    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      c1_outSizeT[c1_i4] = 60.0 + 100.0 * (real_T)c1_i4;
    }

    for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
      c1_connDimsT[c1_i6] = 13.0 + -12.0 * (real_T)c1_i6;
    }

    ippfilter_real32(&chartInstance->c1_a[0], &c1_b[0], &c1_outSizeT[0], 2.0,
                     &c1_padSizeT[0], &c1_dv[0], &c1_connDimsT[0], true);
  } else {
    for (c1_i1 = 0; c1_i1 < 13; c1_i1++) {
      c1_conn[c1_i1] = true;
    }

    for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
      c1_padSizeT[c1_i3] = 72.0 + 88.0 * (real_T)c1_i3;
    }

    for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
      c1_outSizeT[c1_i5] = 60.0 + 100.0 * (real_T)c1_i5;
    }

    for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
      c1_connDimsT[c1_i7] = 13.0 + -12.0 * (real_T)c1_i7;
    }

    for (c1_i8 = 0; c1_i8 < 2; c1_i8++) {
      c1_startT[c1_i8] = 6.0 + -6.0 * (real_T)c1_i8;
    }

    imfilter_real32(&chartInstance->c1_a[0], &c1_b[0], 2.0, &c1_outSizeT[0], 2.0,
                    &c1_padSizeT[0], &c1_dv[0], 13.0, &c1_conn[0], 2.0,
                    &c1_connDimsT[0], &c1_startT[0], 2.0, true, true);
  }
}

static void c1_padImage(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_a_tmp[9600], real32_T c1_e_a[11520])
{
  static int32_T c1_idxA[320] = { 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
    29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 60, 60, 60, 60, 60, 60,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
    34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52,
    53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71,
    72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
    91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107,
    108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122,
    123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137,
    138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152,
    153, 154, 155, 156, 157, 158, 159, 160 };

  emlrtStack c1_st;
  real_T c1_b_i;
  real_T c1_b_j;
  int32_T c1_c_i;
  int32_T c1_i;
  int32_T c1_j;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_n_emlrtRSI;
  for (c1_j = 0; c1_j < 160; c1_j++) {
    c1_b_j = (real_T)c1_j + 1.0;
    for (c1_i = 0; c1_i < 72; c1_i++) {
      c1_b_i = (real_T)c1_i + 1.0;
      c1_c_i = c1_idxA[(int32_T)c1_b_j + 159];
      c1_e_a[((int32_T)c1_b_i + 72 * ((int32_T)c1_b_j - 1)) - 1] = c1_a_tmp
        [(emlrtDynamicBoundsCheckR2012b(c1_idxA[(int32_T)c1_b_i - 1], 1, 60,
           &c1_e_emlrtBCI, &c1_st) + 60 * (emlrtDynamicBoundsCheckR2012b(c1_c_i,
            1, 160, &c1_f_emlrtBCI, &c1_st) - 1)) - 1];
    }
  }
}

static void c1_b_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_varargin_1[9600], real32_T c1_b[9600])
{
  emlrtStack c1_st;
  real_T c1_connDimsT[2];
  real_T c1_outSizeT[2];
  real_T c1_padSizeT[2];
  real_T c1_startT[2];
  int32_T c1_b_i;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  real32_T c1_e_a[10320];
  real32_T c1_b_varargin_1[9600];
  boolean_T c1_b_modeFlag;
  boolean_T c1_c_modeFlag;
  boolean_T c1_modeFlag;
  boolean_T c1_tooBig;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_l_emlrtRSI;
  for (c1_i = 0; c1_i < 9600; c1_i++) {
    c1_b_varargin_1[c1_i] = c1_varargin_1[c1_i];
  }

  c1_b_padImage(chartInstance, &c1_st, c1_b_varargin_1, c1_e_a);
  c1_tooBig = true;
  for (c1_b_i = 0; c1_b_i < 2; c1_b_i++) {
    c1_tooBig = false;
  }

  if (!c1_tooBig) {
    c1_modeFlag = true;
  } else {
    c1_modeFlag = false;
  }

  if (c1_modeFlag) {
    c1_b_modeFlag = true;
  } else {
    c1_b_modeFlag = false;
  }

  c1_c_modeFlag = c1_b_modeFlag;
  if (c1_c_modeFlag) {
    for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
      c1_padSizeT[c1_i2] = 60.0 + 112.0 * (real_T)c1_i2;
    }

    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      c1_outSizeT[c1_i4] = 60.0 + 100.0 * (real_T)c1_i4;
    }

    for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
      c1_connDimsT[c1_i6] = 1.0 + 12.0 * (real_T)c1_i6;
    }

    ippfilter_real32(&c1_e_a[0], &c1_b[0], &c1_outSizeT[0], 2.0, &c1_padSizeT[0],
                     &c1_dv1[0], &c1_connDimsT[0], true);
  } else {
    for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
      c1_padSizeT[c1_i1] = 60.0 + 112.0 * (real_T)c1_i1;
    }

    for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
      c1_outSizeT[c1_i3] = 60.0 + 100.0 * (real_T)c1_i3;
    }

    for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
      c1_connDimsT[c1_i5] = 1.0 + 12.0 * (real_T)c1_i5;
    }

    for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
      c1_startT[c1_i7] = 6.0 * (real_T)c1_i7;
    }

    imfilter_real32(&c1_e_a[0], &c1_b[0], 2.0, &c1_outSizeT[0], 2.0,
                    &c1_padSizeT[0], &c1_dv2[0], 12.0, &c1_bv[0], 2.0,
                    &c1_connDimsT[0], &c1_startT[0], 2.0, true, true);
  }
}

static void c1_b_padImage(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_a_tmp[9600], real32_T c1_e_a[10320])
{
  static int32_T c1_idxA[344] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
    34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52,
    53, 54, 55, 56, 57, 58, 59, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
    23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41,
    42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
    61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98,
    99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113,
    114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128,
    129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143,
    144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158,
    159, 160, 160, 160, 160, 160, 160, 160 };

  emlrtStack c1_st;
  real_T c1_b_i;
  real_T c1_b_j;
  int32_T c1_c_i;
  int32_T c1_i;
  int32_T c1_j;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_n_emlrtRSI;
  for (c1_j = 0; c1_j < 172; c1_j++) {
    c1_b_j = (real_T)c1_j + 1.0;
    for (c1_i = 0; c1_i < 60; c1_i++) {
      c1_b_i = (real_T)c1_i + 1.0;
      c1_c_i = c1_idxA[(int32_T)c1_b_j + 171];
      c1_e_a[((int32_T)c1_b_i + 60 * ((int32_T)c1_b_j - 1)) - 1] = c1_a_tmp
        [(emlrtDynamicBoundsCheckR2012b(c1_idxA[(int32_T)c1_b_i - 1], 1, 60,
           &c1_e_emlrtBCI, &c1_st) + 60 * (emlrtDynamicBoundsCheckR2012b(c1_c_i,
            1, 160, &c1_f_emlrtBCI, &c1_st) - 1)) - 1];
    }
  }
}

static void c1_c_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_varargin_1[9600], real32_T c1_b[9600])
{
  emlrtStack c1_st;
  real_T c1_connDimsT[2];
  real_T c1_outSizeT[2];
  real_T c1_padSizeT[2];
  real_T c1_startT[2];
  int32_T c1_b_i;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  real32_T c1_e_a[10320];
  real32_T c1_b_varargin_1[9600];
  boolean_T c1_conn[13];
  boolean_T c1_b_modeFlag;
  boolean_T c1_c_modeFlag;
  boolean_T c1_modeFlag;
  boolean_T c1_tooBig;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_l_emlrtRSI;
  for (c1_i = 0; c1_i < 9600; c1_i++) {
    c1_b_varargin_1[c1_i] = c1_varargin_1[c1_i];
  }

  c1_b_padImage(chartInstance, &c1_st, c1_b_varargin_1, c1_e_a);
  c1_tooBig = true;
  for (c1_b_i = 0; c1_b_i < 2; c1_b_i++) {
    c1_tooBig = false;
  }

  if (!c1_tooBig) {
    c1_modeFlag = true;
  } else {
    c1_modeFlag = false;
  }

  if (c1_modeFlag) {
    c1_b_modeFlag = true;
  } else {
    c1_b_modeFlag = false;
  }

  c1_c_modeFlag = c1_b_modeFlag;
  if (c1_c_modeFlag) {
    for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
      c1_padSizeT[c1_i2] = 60.0 + 112.0 * (real_T)c1_i2;
    }

    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      c1_outSizeT[c1_i4] = 60.0 + 100.0 * (real_T)c1_i4;
    }

    for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
      c1_connDimsT[c1_i6] = 1.0 + 12.0 * (real_T)c1_i6;
    }

    ippfilter_real32(&c1_e_a[0], &c1_b[0], &c1_outSizeT[0], 2.0, &c1_padSizeT[0],
                     &c1_dv[0], &c1_connDimsT[0], true);
  } else {
    for (c1_i1 = 0; c1_i1 < 13; c1_i1++) {
      c1_conn[c1_i1] = true;
    }

    for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
      c1_padSizeT[c1_i3] = 60.0 + 112.0 * (real_T)c1_i3;
    }

    for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
      c1_outSizeT[c1_i5] = 60.0 + 100.0 * (real_T)c1_i5;
    }

    for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
      c1_connDimsT[c1_i7] = 1.0 + 12.0 * (real_T)c1_i7;
    }

    for (c1_i8 = 0; c1_i8 < 2; c1_i8++) {
      c1_startT[c1_i8] = 6.0 * (real_T)c1_i8;
    }

    imfilter_real32(&c1_e_a[0], &c1_b[0], 2.0, &c1_outSizeT[0], 2.0,
                    &c1_padSizeT[0], &c1_dv[0], 13.0, &c1_conn[0], 2.0,
                    &c1_connDimsT[0], &c1_startT[0], 2.0, true, true);
  }
}

static void c1_d_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_varargin_1[9600], real32_T c1_b[9600])
{
  emlrtStack c1_st;
  real_T c1_connDimsT[2];
  real_T c1_outSizeT[2];
  real_T c1_padSizeT[2];
  real_T c1_startT[2];
  int32_T c1_b_i;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  real32_T c1_b_varargin_1[9600];
  boolean_T c1_b_modeFlag;
  boolean_T c1_c_modeFlag;
  boolean_T c1_modeFlag;
  boolean_T c1_tooBig;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_l_emlrtRSI;
  for (c1_i = 0; c1_i < 9600; c1_i++) {
    c1_b_varargin_1[c1_i] = c1_varargin_1[c1_i];
  }

  c1_padImage(chartInstance, &c1_st, c1_b_varargin_1, chartInstance->c1_d_a);
  c1_tooBig = true;
  for (c1_b_i = 0; c1_b_i < 2; c1_b_i++) {
    c1_tooBig = false;
  }

  if (!c1_tooBig) {
    c1_modeFlag = true;
  } else {
    c1_modeFlag = false;
  }

  if (c1_modeFlag) {
    c1_b_modeFlag = true;
  } else {
    c1_b_modeFlag = false;
  }

  c1_c_modeFlag = c1_b_modeFlag;
  if (c1_c_modeFlag) {
    for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
      c1_padSizeT[c1_i2] = 72.0 + 88.0 * (real_T)c1_i2;
    }

    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      c1_outSizeT[c1_i4] = 60.0 + 100.0 * (real_T)c1_i4;
    }

    for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
      c1_connDimsT[c1_i6] = 13.0 + -12.0 * (real_T)c1_i6;
    }

    ippfilter_real32(&chartInstance->c1_d_a[0], &c1_b[0], &c1_outSizeT[0], 2.0,
                     &c1_padSizeT[0], &c1_dv1[0], &c1_connDimsT[0], true);
  } else {
    for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
      c1_padSizeT[c1_i1] = 72.0 + 88.0 * (real_T)c1_i1;
    }

    for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
      c1_outSizeT[c1_i3] = 60.0 + 100.0 * (real_T)c1_i3;
    }

    for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
      c1_connDimsT[c1_i5] = 13.0 + -12.0 * (real_T)c1_i5;
    }

    for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
      c1_startT[c1_i7] = 6.0 + -6.0 * (real_T)c1_i7;
    }

    imfilter_real32(&chartInstance->c1_d_a[0], &c1_b[0], 2.0, &c1_outSizeT[0],
                    2.0, &c1_padSizeT[0], &c1_dv2[0], 12.0, &c1_bv[0], 2.0,
                    &c1_connDimsT[0], &c1_startT[0], 2.0, true, true);
  }
}

static void c1_imhist(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, real32_T c1_varargin_1[9600],
                      real_T c1_yout[64])
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  real_T c1_c_i;
  real_T c1_out;
  int32_T c1_b_c;
  int32_T c1_b_i;
  int32_T c1_c;
  int32_T c1_i;
  real32_T c1_b_x;
  real32_T c1_e_a;
  real32_T c1_f_a;
  real32_T c1_idx;
  real32_T c1_x;
  boolean_T c1_b;
  boolean_T c1_b_b;
  boolean_T c1_nanFlag;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_st.site = &c1_t_emlrtRSI;
  c1_b_st.site = &c1_u_emlrtRSI;
  c1_out = 1.0;
  getnumcores(&c1_out);
  for (c1_i = 0; c1_i < 64; c1_i++) {
    c1_yout[c1_i] = 0.0;
  }

  c1_nanFlag = false;
  for (c1_b_i = 0; c1_b_i < 9600; c1_b_i++) {
    c1_c_i = (real_T)c1_b_i + 1.0;
    c1_x = c1_varargin_1[(int32_T)c1_c_i - 1];
    c1_b = muSingleScalarIsNaN(c1_x);
    if (c1_b) {
      c1_nanFlag = true;
      c1_idx = 0.0F;
    } else {
      c1_idx = c1_varargin_1[(int32_T)c1_c_i - 1] * 63.0F + 0.5F;
    }

    if (c1_idx > 63.0F) {
      c1_yout[63]++;
    } else {
      c1_b_x = c1_varargin_1[(int32_T)c1_c_i - 1];
      c1_b_b = muSingleScalarIsInf(c1_b_x);
      if (c1_b_b) {
        c1_yout[63]++;
      } else {
        c1_e_a = c1_idx;
        c1_c = (int32_T)c1_e_a;
        c1_f_a = c1_idx;
        c1_b_c = (int32_T)c1_f_a;
        c1_yout[c1_c] = c1_yout[c1_b_c] + 1.0;
      }
    }
  }

  if (c1_nanFlag) {
    c1_b_st.site = &c1_v_emlrtRSI;
    c1_warning(chartInstance, &c1_b_st);
  }
}

static void c1_warning(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp)
{
  static char_T c1_msgID[27] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm',
    'h', 'i', 's', 't', 'c', ':', 'i', 'n', 'p', 'u', 't', 'H', 'a', 's', 'N',
    'a', 'N', 's' };

  static char_T c1_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c1_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_y = NULL;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv, 10, 0U, 1U, 0U, 2, 1, 7), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_msgID, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  c1_st.site = &c1_w_emlrtRSI;
  c1_b_feval(chartInstance, &c1_st, c1_y, c1_feval(chartInstance, &c1_st, c1_b_y,
              c1_c_y));
}

static void c1_thinAndThreshold(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, boolean_T c1_E[9600], real32_T
  c1_c_dx[9600], real32_T c1_b_dy[9600], real32_T c1_magGrad[9600], real_T
  c1_lowThresh_data[], int32_T c1_lowThresh_size[1], real_T c1_highThresh_data[],
  int32_T c1_highThresh_size[1], boolean_T c1_b_H[9600])
{
  real_T c1_szT[2];
  real_T c1_b_lowThresh;
  real_T c1_highThresh;
  real_T c1_lowThresh;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  boolean_T c1_b_E[9600];
  boolean_T c1_marker[9600];
  c1_i = 1;
  emlrtDynamicBoundsCheckR2012b(c1_i, 1, c1_lowThresh_size[0], &c1_h_emlrtBCI,
    c1_sp);
  c1_lowThresh = c1_lowThresh_data[0];
  c1_b_lowThresh = c1_lowThresh;
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_szT[c1_i1] = 60.0 + 100.0 * (real_T)c1_i1;
  }

  cannythresholding_real32_tbb(&c1_c_dx[0], &c1_b_dy[0], &c1_magGrad[0],
    &c1_szT[0], c1_b_lowThresh, &c1_E[0]);
  c1_i2 = 1;
  emlrtDynamicBoundsCheckR2012b(c1_i2, 1, c1_highThresh_size[0], &c1_g_emlrtBCI,
    c1_sp);
  c1_highThresh = c1_highThresh_data[0];
  for (c1_i3 = 0; c1_i3 < 9600; c1_i3++) {
    c1_marker[c1_i3] = ((real_T)c1_magGrad[c1_i3] > c1_highThresh);
  }

  for (c1_i4 = 0; c1_i4 < 9600; c1_i4++) {
    c1_b_E[c1_i4] = c1_E[c1_i4];
  }

  c1_imreconstruct(chartInstance, c1_marker, c1_b_E, c1_b_H);
}

static void c1_imreconstruct(SFc1_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c1_marker[9600], boolean_T c1_mask[9600], boolean_T
  c1_im[9600])
{
  real_T c1_imSizeT[2];
  int32_T c1_i;
  int32_T c1_i1;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 9600; c1_i++) {
    c1_im[c1_i] = c1_marker[c1_i];
  }

  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_imSizeT[c1_i1] = 60.0 + 100.0 * (real_T)c1_i1;
  }

  ippreconstruct_uint8((uint8_T *)&c1_im[0], (uint8_T *)&c1_mask[0],
                       &c1_imSizeT[0], 2.0);
}

static void c1_hough(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c1_sp, boolean_T c1_varargin_1[9600],
                     real_T c1_h[61380])
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  real_T c1_cost[180];
  real_T c1_sint[180];
  real_T c1_tempBin[60];
  real_T c1_b_j;
  real_T c1_b_k;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_j;
  real_T c1_d_x;
  real_T c1_e_i;
  real_T c1_e_x;
  real_T c1_myRho;
  real_T c1_tempNum;
  real_T c1_x;
  int32_T c1_nonZeroPixelMatrix[9600];
  int32_T c1_rhoIdxVector[341];
  int32_T c1_numNonZeros[160];
  int32_T c1_b_i;
  int32_T c1_b_thetaIdx;
  int32_T c1_c;
  int32_T c1_c_i;
  int32_T c1_c_j;
  int32_T c1_d_i;
  int32_T c1_e_a;
  int32_T c1_f_i;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_j;
  int32_T c1_k;
  int32_T c1_n;
  int32_T c1_rhoIdx;
  int32_T c1_thetaIdx;
  int32_T c1_y;
  boolean_T c1_exitg1;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_cb_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  for (c1_i = 0; c1_i < 180; c1_i++) {
    c1_b_i = c1_i;
    c1_x = (-90.0 + (real_T)c1_b_i) * 3.1415926535897931 / 180.0;
    c1_b_x = c1_x;
    c1_b_x = muDoubleScalarCos(c1_b_x);
    c1_cost[c1_b_i] = c1_b_x;
    c1_c_x = (-90.0 + (real_T)c1_b_i) * 3.1415926535897931 / 180.0;
    c1_d_x = c1_c_x;
    c1_d_x = muDoubleScalarSin(c1_d_x);
    c1_sint[c1_b_i] = c1_d_x;
  }

  c1_b_st.site = &c1_db_emlrtRSI;
  for (c1_j = 0; c1_j < 160; c1_j++) {
    c1_b_j = (real_T)c1_j + 1.0;
    c1_tempNum = 0.0;
    for (c1_c_i = 0; c1_c_i < 60; c1_c_i++) {
      c1_e_i = (real_T)c1_c_i + 1.0;
      if (c1_varargin_1[((int32_T)c1_e_i + 60 * ((int32_T)c1_b_j - 1)) - 1]) {
        c1_tempNum++;
        c1_i2 = (int32_T)c1_tempNum;
        c1_tempBin[emlrtDynamicBoundsCheckR2012b(c1_i2, 1, 60, &c1_j_emlrtBCI,
          &c1_b_st) - 1] = c1_e_i;
      }
    }

    c1_numNonZeros[(int32_T)c1_b_j - 1] = (int32_T)c1_tempNum;
    c1_k = 0;
    c1_exitg1 = false;
    while ((!c1_exitg1) && (c1_k < 60)) {
      c1_b_k = (real_T)c1_k + 1.0;
      if (c1_b_k > c1_tempNum) {
        c1_exitg1 = true;
      } else {
        c1_nonZeroPixelMatrix[((int32_T)c1_b_k + 60 * ((int32_T)c1_b_j - 1)) - 1]
          = (int32_T)c1_tempBin[(int32_T)c1_b_k - 1];
        c1_k++;
      }
    }
  }

  for (c1_thetaIdx = 0; c1_thetaIdx < 180; c1_thetaIdx++) {
    c1_b_thetaIdx = c1_thetaIdx;
    for (c1_d_i = 0; c1_d_i < 341; c1_d_i++) {
      c1_rhoIdxVector[c1_d_i] = 0;
    }

    for (c1_c_j = 0; c1_c_j < 160; c1_c_j++) {
      c1_d_j = (real_T)c1_c_j + 1.0;
      c1_i3 = c1_numNonZeros[(int32_T)c1_d_j - 1] - 1;
      for (c1_f_i = 1; c1_f_i - 1 <= c1_i3; c1_f_i++) {
        c1_b_i = c1_f_i - 1;
        c1_n = c1_nonZeroPixelMatrix[c1_b_i + 60 * ((int32_T)c1_d_j - 1)];
        c1_myRho = (c1_d_j - 1.0) * c1_cost[c1_b_thetaIdx] + ((real_T)c1_n - 1.0)
          * c1_sint[c1_b_thetaIdx];
        c1_e_x = c1_myRho - -170.0;
        c1_y = (int32_T)(c1_e_x + 0.5) + 1;
        c1_rhoIdx = c1_y;
        c1_e_a = c1_rhoIdxVector[emlrtDynamicBoundsCheckR2012b(c1_rhoIdx, 1, 341,
          &c1_k_emlrtBCI, &c1_st) - 1] + 1;
        c1_c = c1_e_a;
        c1_rhoIdxVector[emlrtDynamicBoundsCheckR2012b(c1_rhoIdx, 1, 341,
          &c1_i_emlrtBCI, &c1_st) - 1] = c1_c;
      }
    }

    for (c1_i1 = 0; c1_i1 < 341; c1_i1++) {
      c1_h[c1_i1 + 341 * c1_b_thetaIdx] = (real_T)c1_rhoIdxVector[c1_i1];
    }
  }
}

static void c1_houghpeaks(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real_T c1_varargin_1[61380], real_T c1_peaks_data[],
  int32_T c1_peaks_size[2])
{
  static char_T c1_cv1[47] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
    'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
    'I', 'n', 't', 'e', 'g', 'e', 'r' };

  static char_T c1_cv4[47] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
    'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
    'I', 'n', 't', 'e', 'g', 'e', 'r' };

  static char_T c1_cv7[43] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
    'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
    'O', 'd', 'd' };

  static char_T c1_cv9[43] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'h', 'o', 'u',
    'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'h', 'e', 't', 'a', 'V', 'e', 'c', 't', 'o', 'r', 'S', 'p', 'a', 'c',
    'i', 'n', 'g' };

  static char_T c1_cv[33] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o', 'u',
    'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'I', 'n', 't', 'e', 'g', 'e', 'r' };

  static char_T c1_cv3[33] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o', 'u',
    'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'I', 'n', 't', 'e', 'g', 'e', 'r' };

  static char_T c1_cv6[29] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o', 'u',
    'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'O', 'd', 'd' };

  static char_T c1_cv2[18] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '1', ',', ' ', 'H', ',' };

  static char_T c1_cv5[9] = { 'N', 'H', 'o', 'o', 'd', 'S', 'i', 'z', 'e' };

  static char_T c1_cv8[9] = { 'N', 'H', 'o', 'o', 'd', 'S', 'i', 'z', 'e' };

  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  const mxArray *c1_h_y = NULL;
  const mxArray *c1_i_y = NULL;
  const mxArray *c1_l_y = NULL;
  const mxArray *c1_m_y = NULL;
  const mxArray *c1_y = NULL;
  real_T c1_b_dv[180];
  real_T c1_b_x_data[180];
  real_T c1_thetaInterval[179];
  real_T c1_l_x[178];
  real_T c1_b_default;
  real_T c1_b_ex;
  real_T c1_b_k;
  real_T c1_b_maxVal;
  real_T c1_b_threshold;
  real_T c1_b_thresholdDefault;
  real_T c1_b_val;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_k;
  real_T c1_d_x;
  real_T c1_default;
  real_T c1_e_x;
  real_T c1_ex;
  real_T c1_f_k;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_k;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_j_y;
  real_T c1_k_x;
  real_T c1_k_y;
  real_T c1_m_x;
  real_T c1_maxTheta;
  real_T c1_maxVal;
  real_T c1_minTheta;
  real_T c1_n_x;
  real_T c1_n_y;
  real_T c1_o_x;
  real_T c1_o_y;
  real_T c1_p_x;
  real_T c1_q_x;
  real_T c1_r;
  real_T c1_r_x;
  real_T c1_s_x;
  real_T c1_t_x;
  real_T c1_thetaResolution;
  real_T c1_threshold;
  real_T c1_thresholdDefault;
  real_T c1_u_x;
  real_T c1_val;
  real_T c1_x;
  int32_T c1_b_i;
  int32_T c1_b_j;
  int32_T c1_c_i;
  int32_T c1_c_k;
  int32_T c1_e_k;
  int32_T c1_g_k;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_iPeak;
  int32_T c1_i_k;
  int32_T c1_ix;
  int32_T c1_j;
  int32_T c1_jPeak;
  int32_T c1_j_k;
  int32_T c1_k;
  int32_T c1_k_k;
  int32_T c1_loop_ub;
  int32_T c1_peakIdx;
  int32_T c1_rho;
  int32_T c1_rhoMax;
  int32_T c1_rhoMin;
  int32_T c1_rhoToRemove;
  int32_T c1_theta;
  int32_T c1_thetaMax;
  int32_T c1_thetaMin;
  int32_T c1_thetaToRemove;
  int32_T c1_xoffset;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_b2;
  boolean_T c1_b_p;
  boolean_T c1_c_p;
  boolean_T c1_d_p;
  boolean_T c1_e_p;
  boolean_T c1_exitg1;
  boolean_T c1_f_p;
  boolean_T c1_g_p;
  boolean_T c1_h_p;
  boolean_T c1_isDone;
  boolean_T c1_isThetaAntisymmetric;
  boolean_T c1_p;
  boolean_T c1_rEQ0;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_st.site = &c1_eb_emlrtRSI;
  c1_b_st.site = &c1_fb_emlrtRSI;
  c1_c_st.site = &c1_ib_emlrtRSI;
  c1_c_st.site = &c1_ib_emlrtRSI;
  c1_p = true;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 61380)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_x = c1_varargin_1[(int32_T)c1_b_k - 1];
    c1_b_x = c1_x;
    c1_c_x = c1_b_x;
    if (c1_c_x == c1_x) {
      c1_b_p = true;
    } else {
      c1_b_p = false;
    }

    c1_c_p = c1_b_p;
    if (c1_c_p) {
      c1_k++;
    } else {
      c1_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_p) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv1, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv2, 10, 0U, 1U, 0U, 2, 1, 18),
                  false);
    sf_mex_call(&c1_c_st, &c1_d_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14,
                sf_mex_call(&c1_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_c_st, NULL, "message", 1U, 2U, 14, c1_b_y, 14, c1_c_y)));
  }

  c1_maxVal = 0.0;
  for (c1_c_k = 0; c1_c_k < 61380; c1_c_k++) {
    c1_d_k = (real_T)c1_c_k + 1.0;
    c1_val = c1_varargin_1[(int32_T)c1_d_k - 1];
    if (c1_val > c1_maxVal) {
      c1_maxVal = c1_val;
    }
  }

  c1_thresholdDefault = 0.5 * c1_maxVal;
  c1_b_thresholdDefault = c1_thresholdDefault;
  c1_default = c1_b_thresholdDefault;
  c1_b_default = c1_default;
  c1_threshold = c1_b_default;
  c1_b_threshold = c1_threshold;
  c1_b_st.site = &c1_gb_emlrtRSI;
  c1_c_st.site = &c1_jb_emlrtRSI;
  c1_d_st.site = &c1_ib_emlrtRSI;
  c1_d_st.site = &c1_ib_emlrtRSI;
  c1_d_p = true;
  c1_e_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_e_k < 2)) {
    c1_f_k = (real_T)c1_e_k + 1.0;
    c1_d_x = 9.0 + -4.0 * (real_T)((int32_T)c1_f_k - 1);
    c1_e_x = c1_d_x;
    c1_f_x = c1_e_x;
    if (c1_f_x == c1_d_x) {
      c1_e_p = true;
    } else {
      c1_e_p = false;
    }

    c1_g_p = c1_e_p;
    if (c1_g_p) {
      c1_e_k++;
    } else {
      c1_d_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_d_p) {
    c1_b1 = true;
  } else {
    c1_b1 = false;
  }

  if (!c1_b1) {
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_cv3, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv4, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_cv5, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c1_d_st, &c1_d_emlrtMCI, "error", 0U, 2U, 14, c1_d_y, 14,
                sf_mex_call(&c1_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_d_st, NULL, "message", 1U, 2U, 14, c1_e_y, 14, c1_f_y)));
  }

  c1_d_st.site = &c1_ib_emlrtRSI;
  c1_d_st.site = &c1_ib_emlrtRSI;
  c1_f_p = true;
  c1_g_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_g_k < 2)) {
    c1_h_k = (real_T)c1_g_k + 1.0;
    c1_g_x = 9.0 + -4.0 * (real_T)((int32_T)c1_h_k - 1);
    c1_h_x = c1_g_x;
    c1_i_x = c1_h_x;
    c1_j_x = c1_i_x;
    c1_k_x = c1_j_x;
    c1_r = muDoubleScalarRem(c1_k_x, 2.0);
    c1_rEQ0 = (c1_r == 0.0);
    if (c1_rEQ0) {
      c1_r = 0.0;
    }

    c1_h_p = (c1_r == 1.0);
    if (c1_h_p) {
      c1_g_k++;
    } else {
      c1_f_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_f_p) {
    c1_b2 = true;
  } else {
    c1_b2 = false;
  }

  if (!c1_b2) {
    c1_g_y = NULL;
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_cv6, 10, 0U, 1U, 0U, 2, 1, 29),
                  false);
    c1_h_y = NULL;
    sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_cv7, 10, 0U, 1U, 0U, 2, 1, 43),
                  false);
    c1_i_y = NULL;
    sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_cv8, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c1_d_st, &c1_g_emlrtMCI, "error", 0U, 2U, 14, c1_g_y, 14,
                sf_mex_call(&c1_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_d_st, NULL, "message", 1U, 2U, 14, c1_h_y, 14, c1_i_y)));
  }

  c1_b_st.site = &c1_hb_emlrtRSI;
  c1_c_st.site = &c1_lb_emlrtRSI;
  c1_d_st.site = &c1_ib_emlrtRSI;
  for (c1_i = 0; c1_i < 180; c1_i++) {
    c1_b_dv[c1_i] = -90.0 + (real_T)c1_i;
  }

  c1_diff(chartInstance, c1_b_dv, c1_thetaInterval);
  c1_c_st.site = &c1_kb_emlrtRSI;
  c1_b_diff(chartInstance, c1_thetaInterval, c1_l_x);
  c1_j_y = c1_l_x[0];
  for (c1_i_k = 0; c1_i_k < 177; c1_i_k++) {
    c1_xoffset = c1_i_k;
    c1_ix = c1_xoffset;
    c1_j_y += c1_l_x[c1_ix + 1];
  }

  c1_m_x = c1_j_y;
  c1_n_x = c1_m_x;
  c1_o_x = c1_n_x;
  c1_k_y = muDoubleScalarAbs(c1_o_x);
  if (c1_k_y > 1.4901161193847656E-8) {
    c1_l_y = NULL;
    sf_mex_assign(&c1_l_y, sf_mex_create("y", c1_cv9, 10, 0U, 1U, 0U, 2, 1, 43),
                  false);
    c1_m_y = NULL;
    sf_mex_assign(&c1_m_y, sf_mex_create("y", c1_cv9, 10, 0U, 1U, 0U, 2, 1, 43),
                  false);
    sf_mex_call(&c1_b_st, &c1_h_emlrtMCI, "error", 0U, 2U, 14, c1_l_y, 14,
                sf_mex_call(&c1_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_b_st, NULL, "message", 1U, 1U, 14, c1_m_y)));
  }

  c1_isDone = false;
  for (c1_i1 = 0; c1_i1 < 61380; c1_i1++) {
    chartInstance->c1_hnew[c1_i1] = c1_varargin_1[c1_i1];
  }

  c1_peakIdx = 0;
  for (c1_i2 = 0; c1_i2 < 180; c1_i2++) {
    c1_b_x_data[c1_i2] = -90.0 + (real_T)c1_i2;
  }

  c1_ex = c1_b_x_data[0];
  for (c1_j_k = 0; c1_j_k < 179; c1_j_k++) {
    if (c1_ex > c1_b_x_data[c1_j_k + 1]) {
      c1_ex = c1_b_x_data[c1_j_k + 1];
    }
  }

  c1_minTheta = c1_ex;
  for (c1_i3 = 0; c1_i3 < 180; c1_i3++) {
    c1_b_x_data[c1_i3] = -90.0 + (real_T)c1_i3;
  }

  c1_b_ex = c1_b_x_data[0];
  for (c1_k_k = 0; c1_k_k < 179; c1_k_k++) {
    if (c1_b_ex < c1_b_x_data[c1_k_k + 1]) {
      c1_b_ex = c1_b_x_data[c1_k_k + 1];
    }
  }

  c1_maxTheta = c1_b_ex;
  c1_p_x = c1_maxTheta - c1_minTheta;
  c1_q_x = c1_p_x;
  c1_r_x = c1_q_x;
  c1_n_y = muDoubleScalarAbs(c1_r_x);
  c1_thetaResolution = c1_n_y / 179.0;
  c1_s_x = c1_minTheta + c1_thetaResolution * 5.0;
  c1_t_x = c1_s_x;
  c1_u_x = c1_t_x;
  c1_o_y = muDoubleScalarAbs(c1_u_x);
  c1_isThetaAntisymmetric = (c1_o_y <= c1_maxTheta);
  while (!c1_isDone) {
    c1_iPeak = 0;
    c1_jPeak = 0;
    c1_b_maxVal = -1.0;
    for (c1_j = 0; c1_j < 180; c1_j++) {
      c1_b_j = c1_j;
      for (c1_b_i = 0; c1_b_i < 341; c1_b_i++) {
        c1_c_i = c1_b_i;
        c1_b_val = chartInstance->c1_hnew[c1_c_i + 341 * c1_b_j];
        if (c1_b_val > c1_b_maxVal) {
          c1_iPeak = c1_c_i + 1;
          c1_jPeak = c1_b_j + 1;
          c1_b_maxVal = c1_b_val;
        }
      }
    }

    if (chartInstance->c1_hnew[(emlrtDynamicBoundsCheckR2012b(c1_iPeak, 1, 341,
          &c1_m_emlrtBCI, c1_sp) + 341 * (emlrtDynamicBoundsCheckR2012b(c1_jPeak,
           1, 180, &c1_n_emlrtBCI, c1_sp) - 1)) - 1] >= c1_b_threshold) {
      c1_peakIdx++;
      chartInstance->c1_peakCoordinates[emlrtDynamicBoundsCheckR2012b(c1_peakIdx,
        1, 61380, &c1_l_emlrtBCI, c1_sp) - 1] = (real_T)c1_iPeak;
      chartInstance->c1_peakCoordinates[c1_peakIdx + 61379] = (real_T)c1_jPeak;
      c1_rhoMin = c1_iPeak - 4;
      c1_rhoMax = c1_iPeak + 4;
      c1_thetaMin = c1_jPeak;
      c1_thetaMax = c1_jPeak;
      if (c1_rhoMin < 1) {
        c1_rhoMin = 1;
      }

      if (c1_rhoMax > 341) {
        c1_rhoMax = 341;
      }

      for (c1_theta = c1_thetaMin - 2; c1_theta <= c1_thetaMax + 2; c1_theta++)
      {
        for (c1_rho = c1_rhoMin; c1_rho <= c1_rhoMax; c1_rho++) {
          c1_rhoToRemove = c1_rho;
          c1_thetaToRemove = c1_theta;
          if (c1_isThetaAntisymmetric) {
            if (c1_theta > 180) {
              c1_rhoToRemove = 342 - c1_rho;
              c1_thetaToRemove = c1_theta - 180;
            } else {
              if (c1_theta < 1) {
                c1_rhoToRemove = 342 - c1_rho;
                c1_thetaToRemove = c1_theta + 180;
              }
            }
          }

          if ((c1_thetaToRemove > 180) || (c1_thetaToRemove < 1)) {
          } else {
            chartInstance->c1_hnew[(c1_rhoToRemove + 341 * (c1_thetaToRemove - 1))
              - 1] = 0.0;
          }
        }
      }

      c1_isDone = (c1_peakIdx == 2);
    } else {
      c1_isDone = true;
    }
  }

  if (c1_peakIdx == 0) {
    c1_peaks_size[0] = 0;
    c1_peaks_size[1] = 0;
  } else {
    c1_i4 = c1_peakIdx - 1;
    c1_peaks_size[0] = c1_i4 + 1;
    c1_peaks_size[1] = 2;
    for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
      c1_loop_ub = c1_i4;
      for (c1_i6 = 0; c1_i6 <= c1_loop_ub; c1_i6++) {
        c1_peaks_data[c1_i6 + c1_peaks_size[0] * c1_i5] =
          chartInstance->c1_peakCoordinates[c1_i6 + 61380 * c1_i5];
      }
    }
  }
}

static void c1_diff(SFc1_flightControlSystemInstanceStruct *chartInstance,
                    real_T c1_x[180], real_T c1_y[179])
{
  real_T c1_tmp1;
  real_T c1_tmp2;
  real_T c1_work;
  int32_T c1_ixLead;
  int32_T c1_iyLead;
  int32_T c1_m;
  (void)chartInstance;
  c1_ixLead = 1;
  c1_iyLead = 0;
  c1_work = c1_x[0];
  for (c1_m = 0; c1_m < 179; c1_m++) {
    c1_tmp1 = c1_x[c1_ixLead];
    c1_tmp2 = c1_work;
    c1_work = c1_tmp1;
    c1_tmp1 -= c1_tmp2;
    c1_ixLead++;
    c1_y[c1_iyLead] = c1_tmp1;
    c1_iyLead++;
  }
}

static void c1_b_diff(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      real_T c1_x[179], real_T c1_y[178])
{
  real_T c1_tmp1;
  real_T c1_tmp2;
  real_T c1_work;
  int32_T c1_ixLead;
  int32_T c1_iyLead;
  int32_T c1_m;
  (void)chartInstance;
  c1_ixLead = 1;
  c1_iyLead = 0;
  c1_work = c1_x[0];
  for (c1_m = 0; c1_m < 178; c1_m++) {
    c1_tmp1 = c1_x[c1_ixLead];
    c1_tmp2 = c1_work;
    c1_work = c1_tmp1;
    c1_tmp1 -= c1_tmp2;
    c1_ixLead++;
    c1_y[c1_iyLead] = c1_tmp1;
    c1_iyLead++;
  }
}

static real_T c1_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_Angle, const char_T *c1_identifier)
{
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Angle), &c1_thisId);
  sf_mex_destroy(&c1_b_Angle);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_d;
  real_T c1_y;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static uint8_T c1_c_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_flightControlSystem, const
  char_T *c1_identifier)
{
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_flightControlSystem), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_flightControlSystem);
  return c1_y;
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_b_u;
  uint8_T c1_y;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b_u, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_b_u;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static const mxArray *c1_chart_data_browse_helper
  (SFc1_flightControlSystemInstanceStruct *chartInstance, int32_T c1_ssIdNumber)
{
  const mxArray *c1_mxData = NULL;
  real_T c1_d;
  c1_mxData = NULL;
  switch (c1_ssIdNumber) {
   case 4U:
    sf_mex_assign(&c1_mxData, sf_mex_create("mxData", *chartInstance->c1_BW, 11,
      0U, 1U, 0U, 2, 60, 160), false);
    break;

   case 5U:
    c1_d = *chartInstance->c1_Angle;
    sf_mex_assign(&c1_mxData, sf_mex_create("mxData", &c1_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;
  }

  return c1_mxData;
}

static const mxArray *c1_feval(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, const mxArray *c1_input0, const
  mxArray *c1_input1)
{
  const mxArray *c1_ = NULL;
  (void)chartInstance;
  c1_ = NULL;
  sf_mex_assign(&c1_, sf_mex_call(c1_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c1_input0), 14, sf_mex_dup(c1_input1)), false);
  sf_mex_destroy(&c1_input0);
  sf_mex_destroy(&c1_input1);
  return c1_;
}

static void c1_b_feval(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, const mxArray *c1_input0, const mxArray *c1_input1)
{
  (void)chartInstance;
  sf_mex_call(c1_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c1_input0), 14,
              sf_mex_dup(c1_input1));
  sf_mex_destroy(&c1_input0);
  sf_mex_destroy(&c1_input1);
}

static void init_dsm_address_info(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c1_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_BW = (boolean_T (*)[9600])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_Angle = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c1_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(679345067U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(557033792U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2550536699U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2595367480U);
}

mxArray *sf_c1_flightControlSystem_third_party_uses_info(void)
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

mxArray *sf_c1_flightControlSystem_jit_fallback_info(void)
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

mxArray *sf_c1_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPhDBxMDABqQ4IEwwYIXyGaFijHBxFri4AhCXVBakgsSLi5I9U4B0XmIumJ9YWuG"
    "Zl5YPNt+CAWE+GxbzGZHM54SKQ8AHe8r0izig62fBop8VSb8AlO+Yl56TCgsfKE2+OxQcKNMPsT"
    "+AgD8U0PwB4mcWxycml2SWpcYnG8an5WSmZ5Q45+eVFOXnBFcWl6TmwvwHAELmHTw="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sl2lqyMfYDOfD9eWtICA0rG";
}

static void sf_opaque_initialize_c1_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c1_flightControlSystem
    ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_flightControlSystem(void *chartInstanceVar)
{
  enable_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_flightControlSystem(void *chartInstanceVar)
{
  disable_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c1_flightControlSystem
    ((SFc1_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c1_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c1_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c1_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_flightControlSystem(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
    initSimStructsc1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c1_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [19] = {
    "eNrtV01v2zYYVoy0WIE2CIYBvRRobtsx7Wm7bIlluzMQL0HltOgpYKhXFmGKVPmh2Nhh9/2C/Yw",
    "deh6w8/YD9jN23LEvJcVxZUmu5zXohglgFIrP+/D9Ju3tDEcePns4fvrU8+7i+xMcHa947pTzna",
    "VRfN/1Pi/nb1BI2OSMKJJor/URJIHnoCW3hkkxFJGshTERgQJBEZtKZZrYNEssZ2I6sII6Pv0yZ",
    "jQOYml52EVZEp4KPke21Joz5OkxBdQMAEITK2kn8YCTyUJjZa78GOhU26TNBA0msKlTS48sNyzl",
    "0J8BHQptCGqsb3QLDDHgm1mjmc5SHVwDZZJyRkSttTHRAaToYAPnaYh/T61Bo6owGhNluhCTDPQ",
    "Jm+acUkCVk2lcuGSCGKkY4f2E+05wVbczjvqMZAi8xSGoW1cBmaaSCdMc/2CAlvYFueTQg0s7aW",
    "YL4LV1wX/B4ApUo98iX2agyAROReOmuUP6szxaiyxZhRmWwAuijinGT0PYmL2YOTogGCcYo0QTD",
    "HIjh3qsWIbubWSzydBl5rqSsUkRbL0OlrP1M2iLwoJtQIVPONeNsLFMTyADnrP2iCHtsIK1Hqc1",
    "C8cSHezSu7karGAY+BLmSxGy2nBlFUDed77DxvIuklptZOJj8vZOTlaXV2FDYUBFhEJdF1CEaUC",
    "f5e5tZguZdrFHIGplcvXqwEWGrEN5OrKidyXVFH3S0kRuTHARbQQmeoKxxEo411g0bTAXy3U4Sm",
    "gMoWswjMMIywaxNT7RrrUdY91lzMx7oKliaU1ULVYdtqG+S6h5CudiKuSVGCiZBGWPL6KAnQF7e",
    "IIxGOc1JihSMW2wXbCb7UMATEqiBBOTLrY5NR+gkrURc+feoXdz7t1/j3PvWq76/mKJZ6eGx1t6",
    "V/e912nft4P/7ZRyR0tyDyr77FbkHG4fx6+/dLMfZ7Pf//rth/vfP3zzZJv9f+5sdk/YK+ePrhv",
    "yosCylbx22G+X9Nqt4X+4xL9fzjV/yl/PR9Gr3mnU+wpemqF/fKieFfFZo2+nou/19wN3MmA25n",
    "ms6DAsLzBuTmxxrDv+L5f0vbvGH/fK78Xz5zfbyX92VJWv89edir/c/FhMOFTy9+/rcXC0nXyx/",
    "9kaOw4qdhzk94AL4roLXNAnFxFnk9gdDEZJHsyxLSR7/0C9bSrn3bLcv0XP//3y4e17n/PrtuW8",
    "W5bb1r5Nz/GPDX/Y0ke9Cn7/I7Zj2/vVh8b/4W12D3pczr9e/CTyY8bDmttxuYx32Khu9T+Sp5v",
    "g3wKhi8H/",
    ""
  };

  static char newstr [1285] = "";
  newstr[0] = '\0';
  for (i = 0; i < 19; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c1_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c1_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1984085697U));
  ssSetChecksum1(S,(3430447242U));
  ssSetChecksum2(S,(209701880U));
  ssSetChecksum3(S,(833886075U));
}

static void mdlRTW_c1_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c1_flightControlSystem(SimStruct *S)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc1_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c1_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c1_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c1_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_flightControlSystem;
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
    chartInstance->c1_JITStateAnimation,
    chartInstance->c1_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c1_flightControlSystem(chartInstance);
}

void c1_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c1_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
